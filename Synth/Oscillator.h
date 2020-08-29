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
#include <math.h>

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
	};

	enum OscillatorType
	{
		OSCILLATOR_POLYBLEP,
		OSCILLATOR_WAVETABLE, //band limited wavetable
		OSCILLATOR_NAIVE,
	};

	enum OscillatorOversampling
	{
		OSCILLATOR_OVERSAMPLING_NONE,
		OSCILLATOR_OVERSAMPLING_2X,
	};

	class Oscillator : public TimedSynthComponent {
	public:
		Oscillator();
		virtual ~Oscillator();
		void initFreqIncTab(int samplerate);
		void start();
		void stop();
		void setNote(char t_note);
		inline float Oscillator::poly2blepSaw(float phase, float dt) //polyblep for saw
		{
			float p = 0;
			if (phase < dt)	// 0 <= t < 1
			{
				p = phase / dt;
				return p + p - p * p - 1.0f;	// 2 * (t - t ^ 2 / 2 - 0.5)
			}
			else if (phase > (1 - dt))	// -1 < t < 0
			{
				p = (phase - 1) / dt;
				return p * p + p + p + 1.0f;	// 2 * (t ^ 2 / 2 + t + 0.5)
			}
			else
			{
				return 0;
			}
		};
		inline float Oscillator::poly2blepSquare(float phase, float dt) //polyblep for square. Performance is same with saw polyblep but a bit less computation
		{
			float p = 0;
			if (phase < dt)	// 0 <= t < 1
			{
				p = phase / dt - 1;
				return -(p * p);	// -p^2
			}
			else if (phase > (1 - dt))	// -1 < t < 0
			{
				p = (phase - 1) / dt + 1;
				return p * p; // p^2
			}
			else
			{
				return 0;
			}
		};
		inline float Oscillator::sawPolyBlep(float phase, float dt)
		{
			float value = 2.0f * phase - 1.0f;
			return value -= poly2blepSaw(phase, dt);
		};
		inline float Oscillator::squarePolyBlep(float phase, float dt, float pw)
		{
			float value;
			if (phase < pw)
			{
				value = 1.0f;
			}
			else
			{
				value = -1.0f;
			}
			value += poly2blepSquare(phase, dt);
			return value -= poly2blepSquare(fmodf(phase + (1 - pw), 1.0f), dt);
		};
		inline float Oscillator::run()
		{
			currentValue = 0.0f;
			switch (m_oscwaveform)
			{
			case OSCILLATOR_SINE:
			{
				switch (m_osctype)
				{
				case OSCILLATOR_POLYBLEP:
				{

				}
				case OSCILLATOR_WAVETABLE:
				{
					currentValue = m_wavetable->table[(int)(m_phase * (float)m_wavetable->len)]; //need to cast len to float for some reason
					break;
				}
				case OSCILLATOR_NAIVE:
				{
					break;
				}
				}
				break;
			}
			case OSCILLATOR_SQUARE:
			{
				switch (m_osctype)
				{
				case OSCILLATOR_POLYBLEP:
				{
					currentValue = squarePolyBlep(m_phase, m_phaseInc, 0.5f);
					break;
				}
				case OSCILLATOR_WAVETABLE:
				{
					currentValue = m_wavetable->table[(int)(m_phase * (float)m_wavetable->len)]; //need to cast len to float for some reason
					break;
				}
				case OSCILLATOR_NAIVE:
				{
					if (m_phase < 0.5f)
					{
						currentValue = 1.0f;
					}
					else
					{
						currentValue = -1.0f;
					}
					break;
				}
				}
				break;
			}
			case OSCILLATOR_TRIANGLE:
			{
				switch (m_osctype)
				{
				case OSCILLATOR_POLYBLEP:
				{

				}
				case OSCILLATOR_WAVETABLE:
				{
					currentValue = m_wavetable->table[(int)(m_phase * (float)m_wavetable->len)]; //need to cast len to float for some reason
					break;
				}
				case OSCILLATOR_NAIVE:
				{
					break;
				}
				}
				break;
			}
			case OSCILLATOR_SAW:
			{
				switch (m_osctype)
				{
				case OSCILLATOR_POLYBLEP:
				{
					currentValue = sawPolyBlep(m_phase, m_phaseInc);
					break;
				}
				case OSCILLATOR_WAVETABLE:
				{
					currentValue = m_wavetable->table[(int)(m_phase * (float)m_wavetable->len)]; //need to cast len to float for some reason
					break;
				}
				case OSCILLATOR_NAIVE:
				{
					currentValue = 2.0f * m_phase - 1.0f;
					break;
				}
				}
				break;
			}
			default:
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
		OscillatorWaveform m_oscwaveform = OSCILLATOR_SQUARE;
		OscillatorType m_osctype = OSCILLATOR_POLYBLEP;
		static float m_freqIncTable[128];
		static bool m_init;
		bool m_oscOn;

	};
}
#endif /* OSCILLATOR_H_ */
