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



class Synth {
public:
	Synth();
	virtual ~Synth();
	void noteOn();
	void noteOff();
	float run();
	float getCurrentSample();

private:
	Voice voices[MAX_VOICES];
	Instrument instruments[MAX_INSTRUMENTS];

};



#endif /* SYNTH_H_ */
