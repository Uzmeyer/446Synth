/*
 * Voice.cpp
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#include "Voice.h"
namespace glock
{
	Voice::Voice() {
		// TODO Auto-generated constructor stub
		m_currentInstrument = nullptr;
		m_currentNote = -1;
		m_velocity = 0.0f;
		m_samplerate = 0;
		m_state = VOICE_STATE_OFF;
	}

	Voice::~Voice() {
		// TODO Auto-generated destructor stub
	}

	void Voice::Init(int t_samplerate)
	{
		m_samplerate = t_samplerate;
		m_osc1.initFreqIncTab(t_samplerate);
		m_osc2.initFreqIncTab(t_samplerate);
		m_env1.init(t_samplerate);
		m_env1.updatePhaseIncs();
	}

	void Voice::noteOn(char t_note, char t_velocity)
	{
		m_currentNote = t_note;
		m_velocity = t_velocity * midiMaxInv;
		m_state = VOICE_STATE_ON;
		m_osc1.setNote(t_note);
		m_osc1.reset();
		m_osc1.start();
		m_osc2.setNote(t_note - 12);
		m_osc2.reset();
		m_osc2.start();
		m_env1.noteOn();
	}

	void Voice::noteOn(char t_note, char t_velocity, Instrument *t_instrument)
	{
		m_currentNote = t_note;
		m_velocity = t_velocity * midiMaxInv;
		m_currentInstrument = t_instrument;
		m_state = VOICE_STATE_ON;
		m_osc1.setNote(t_note);
		m_osc1.reset();
		m_osc1.start();
		m_osc2.setNote(t_note - 12);
		m_osc2.reset();
		m_osc2.start();
		m_env1.noteOn();
	}

	void Voice::noteRestart(char t_note, char t_velocity)
	{
		m_currentNote = t_note;
		m_velocity = t_velocity * midiMaxInv;
		m_state = VOICE_STATE_ON;
		m_osc1.setNote(t_note);
		m_osc1.start();
		m_osc2.setNote(t_note - 12);
		m_osc2.start();
		m_env1.noteOn();
	}

	void Voice::noteRestart(char t_note, char t_velocity, Instrument* t_instrument)
	{
		m_currentNote = t_note;
		m_velocity = t_velocity * midiMaxInv;
		m_currentInstrument = t_instrument;
		m_state = VOICE_STATE_ON;
		m_osc1.setNote(t_note);
		m_osc1.start();
		m_osc2.setNote(t_note - 12);
		m_osc2.start();
		m_env1.noteOn();
	}

	void Voice::noteOff()
	{
		m_state = VOICE_STATE_RELEASED;
		m_env1.noteOff();
	}

	float Voice::run()
	{
		m_currentSample = 0.0f;
		m_currentSample += (( m_osc2.run() + 0.5 * m_osc1.run()) * m_env1.run());
		m_currentSample = m_currentSample * m_velocity;
		if (m_env1.getState() == ENVELOPE_STATE_OFF)
		{
			m_state = VOICE_STATE_OFF;
		}
		return m_currentSample;
	}

	void Voice::setInstrument(Instrument *t_instrument)
	{
		m_currentInstrument = t_instrument;
	}

	char Voice::getNote()
	{
		return m_currentNote;
	}

	Instrument* Voice::getCurrentInstrument()
	{
		return m_currentInstrument;
	}

	int Voice::getState()
	{
		return m_state;
	}

}