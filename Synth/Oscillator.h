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

extern Wavetable wavetables[];

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
};

class Oscillator: public TimedSynthComponent {
public:
	Oscillator();
	virtual ~Oscillator();

	inline float Oscillator::run()
	{
		currentValue = 0.0f;
		switch (osctype)
		{
		case OSCILLATOR_WAVETABLE:
		{
			currentValue = wavetable->table[(int)phase * wavetable->len];
			break;
		}
		case OSCILLATOR_NAIVE:
		{
			break;
		}
		}
		 
		phase += phaseinc;
		if(phase >= 1.0f)
		{
			phase -= 1.0f;
		}

		return currentValue;
	};

	float getCurrentValue();

private:
	float phase = 0.0f;
	float phaseinc = 0.0f;
	float wavemod = 0.5f;
	Wavetable* wavetable = &wavetables[OSCILLATOR_SINE];
	OscillatorWaveform oscwaveform = OSCILLATOR_SINE;
	OscillatorType osctype = OSCILLATOR_WAVETABLE;

};

#endif /* OSCILLATOR_H_ */
