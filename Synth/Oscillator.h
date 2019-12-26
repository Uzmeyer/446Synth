/*
 * Oscillator.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "TimedSynthComponent.h"
#include "Wavetable.h"
#include "Midi.h"

namespace glock
{
	extern struct Wavetable wavetables[];
	extern float midiFrequencies[128];

	enum OscillatorWaveform
	{
		OSCILLATOR_SINE,
		OSCILLATOR_SQUARE,
		OSCILLATOR_TRIANGLE,
		OSCILLATOR_SAW,
		OSCILLATOR_TRAPEZOID,
	};

	enum OscillatorType
	{
		OSCILLATOR_WAVETABLE, //band limited wavetable
		OSCILLATOR_NAIVE,
		OSCILLATOR_POLYBLEP,

	};

	class Oscillator : public TimedSynthComponent {
	public:
		Oscillator();
		virtual ~Oscillator();
		void initFreqIncTab(int samplerate);
		void start();
		void stop();
		void setNote(char t_note);
		inline float Oscillator::run()
		{
			currentValue = 0.0f;
			switch (m_osctype)
			{
			case OSCILLATOR_WAVETABLE:
			{
				currentValue = m_wavetable->table[(int) (m_phase * (float) m_wavetable->len)]; //need to cast len to float for some reason
				break;
			}
			case OSCILLATOR_NAIVE:
			{
				break;
			}
			}

			m_phase += m_phaseInc;
			if (m_phase >= 1.0f)
			{
				m_phase -= 1.0f;
			}

			return currentValue;
		};

		float getCurrentValue();
		void reset();
	private:
		float m_phase = 0.0f;
		float m_phaseInc = 0.0f;
		float m_wavemod = 0.5f;
		Wavetable* m_wavetable;
		OscillatorWaveform m_oscwaveform = OSCILLATOR_SINE;
		OscillatorType m_osctype = OSCILLATOR_WAVETABLE;
		static float m_freqIncTable[128];
		static bool m_init;
		bool m_oscOn;

	};
}
#endif /* OSCILLATOR_H_ */
