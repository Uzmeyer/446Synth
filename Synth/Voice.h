/*
 * Voice.h
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#ifndef VOICE_H_
#define VOICE_H_

#include "Oscillator.h"
#include "Envelope.h"
namespace glock
{
	extern const float midiMaxInv;

	enum VoiceState
	{
		VOICE_STATE_OFF = 0,
		VOICE_STATE_ON,
		VOICE_STATE_RELEASED,
	};

	class Instrument;
		class Voice {
	public:
		Voice();
		virtual ~Voice();
		void Init(int t_samplerate);
		void noteOn(char t_note, char t_velocity);
		void noteOn(char t_note, char t_velocity, Instrument *t_instrument);
		void noteRestart(char t_note, char t_velocity);
		void noteRestart(char t_note, char t_velocity, Instrument* t_instrument);
		void noteOff();
		float run();
		void setInstrument(Instrument *t_instrument);
		char getNote();
		Instrument* getCurrentInstrument();
		int getState();

	private:
		Instrument* m_currentInstrument = nullptr;
		char m_currentNote;
		VoiceState m_state = VOICE_STATE_OFF;
		int m_samplerate;
		float m_velocity;
		Oscillator m_osc1;
		Oscillator m_osc2;
		Envelope m_env1;
		float m_currentSample;
	};
}
#endif /* VOICE_H_ */
