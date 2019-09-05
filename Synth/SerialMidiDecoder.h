/*
 * SerialMidiDecoder.h
 *
 *  Created on: 22.05.2019
 *      Author: Jakob
 */

#ifndef SERIALMIDIDECODER_H_
#define SERIALMIDIDECODER_H_

#include <MidiDecoder.h>
#include "RingBuffer.h"


class SerialMidiDecoder: public MidiDecoder {
public:
	SerialMidiDecoder(Synth* synth, RingBuffer<unsigned char, MIDIBUFFERSIZE>* buffer);
	virtual ~SerialMidiDecoder();
	void getNextByte();

private:
	RingBuffer<unsigned char, MIDIBUFFERSIZE>* buffer;
};



#endif /* SERIALMIDIDECODER_H_ */
