/*
 * Instrument.h
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include "SystemCommon.h"
#include "Voice.h"
#include "VirtualPatch.h"

class Instrument {
public:
	Instrument();
	virtual ~Instrument();
	void noteOn();
	void noteOff();

private:
	struct VirtualPatch patch;
	Voice* voices[MAX_VOICES];
};

#endif /* INSTRUMENT_H_ */
