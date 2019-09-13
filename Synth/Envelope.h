/*
 * Envelope.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef ENVELOPE_H_
#define ENVELOPE_H_

#include <TimedSynthComponent.h>

extern const float expAttackTable[];
#define EXPATABLELEN 63 //onle less for interpolation

enum EnvelopeState
{
	ENVELOPE_STATE_A = 0,
	ENVELOPE_STATE_D,
	ENVELOPE_STATE_S,
	ENVELOPE_STATE_R,
	ENVELOPE_STATE_OFF,
	ENVELOPE_NUM_STATES
};

enum EnvelopeMode
{
	ENVELOPE_MODE_LIN = 0,
	ENVELOPE_MODE_EXP 
};

class Envelope: public TimedSynthComponent {
public:
	Envelope();
	virtual ~Envelope();
	void noteOn();
	void noteOff();
	void newState();

	inline float run()
	{
		phase += phaseinc; //increment before calculation to save calculation in case of rollover
		if (phase >= 1.0)
		{
			newState();
			return currentValue;
		}

		if (currentMode) //ENVELOPE_MODE_EXP = 1
		{
			float temp = phase * EXPATABLELEN; //get index as float
			int intPart = (int)temp;
			float fracPart = temp - intPart;
			float sample0 = expAttackTable[intPart]; //get lower sample
			float sample1 = expAttackTable[intPart + 1]; //get higher sample
			temp = sample0 + (sample1 - sample0) * fracPart; //yes, reusing variables is not smart
			currentValue = temp * valueDifference + previousstatevalue; //scale and move to current needed output range, exp direction is switched by negative difference
		}
		else
		{
			currentValue = phase * valueDifference + previousstatevalue; //almost trivial
		}
		return currentValue;
	};

private:
	EnvelopeState currentstate;
	EnvelopeMode currentMode;
	float attack;
	float decay;
	float sustain;
	float release;
	float attackInc;
	float decayInc;
	float releaseInc;
	float phase;
	float phaseinc;
	float previousstatevalue;
	float targetvalue;
	float valueDifference;
};

#endif /* ENVELOPE_H_ */
