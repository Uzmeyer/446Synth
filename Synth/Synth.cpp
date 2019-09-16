/*
 * Synth.cpp
 *
 *  Created on: 22.05.2019
 *      Author: Jakob
 */

#include "Synth.h"

namespace glock
{

	Synth::Synth() {
		// TODO Auto-generated constructor stub
		m_currentSample = 0.0f;
	}

	Synth::~Synth() {
		// TODO Auto-generated destructor stub
	}

	void Synth::Init(int t_samplerate)
	{
		for (int i = 0; i < MAX_INSTRUMENTS; i++)
		{
			m_instruments[i].Init(m_voices, t_samplerate);
		}
		for (int i = 0; i < MAX_VOICES; i++)
		{
			m_voices[i].Init(t_samplerate);
		}
	}

	void Synth::noteOn(char instrument, char note, char velocity)
	{
		if (velocity == 0)
		{
			m_instruments[instrument].noteOff(note);
		}
		else
		{
			m_instruments[instrument].noteOn(note, velocity);
		}
	}

	void Synth::noteOff(char instrument, char note)
	{
		m_instruments[instrument].noteOff(note);
	}


	float Synth::run()
	{
		m_currentSample = 0.0f;

		for (int i = 0; i < MAX_VOICES; i++)
		{
			if (m_voices[i].getState() > VOICE_STATE_OFF)
			{
				m_currentSample += m_voices[i].run();
			}
					}
		return m_currentSample;
	}

	float Synth::getCurrentSample()
	{
		return m_currentSample;
	}

}