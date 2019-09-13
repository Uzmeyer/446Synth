/*
 * Voice.h
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#ifndef VOICE_H_
#define VOICE_H_

class Instrument;

class Voice {
public:
	Voice();
	virtual ~Voice();

private:
	Instrument* currentInstrument = nullptr;
};

#endif /* VOICE_H_ */
