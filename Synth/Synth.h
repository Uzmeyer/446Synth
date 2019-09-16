/*
 * Synth.h
 *
 *  Created on: 22.05.2019
 *      Author: Jakob
 */

#ifndef SYNTH_H_
#define SYNTH_H_

#include "Midi.h"
#include "Oscillator.h"
#include "Instrument.h"
#include "Voice.h"
#include "SystemCommon.h"

namespace glock
{

	class Synth {
	public:
		Synth();
		virtual ~Synth();
		void Init(int t_samplerate);
		void noteOn(char instrument, char note, char velocity);
		void noteOff(char instrument, char note);
		float run();
		float getCurrentSample();

	private:
		Voice m_voices[MAX_VOICES];
		Instrument m_instruments[MAX_INSTRUMENTS];
		float m_currentSample;

	};

}

#endif /* SYNTH_H_ */
