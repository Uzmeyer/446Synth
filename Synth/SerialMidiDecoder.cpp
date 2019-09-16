/*
 * SerialMidiDecoder.cpp
 *
 *  Created on: 22.05.2019
 *      Author: Jakob
 */

#include "SerialMidiDecoder.h"

namespace glock
{

	SerialMidiDecoder::SerialMidiDecoder(Synth* synth, RingBuffer<unsigned char, 32> * buffer) : MidiDecoder(synth)
	{
		this->buffer = buffer;
	}

	SerialMidiDecoder::~SerialMidiDecoder() {
		// TODO Auto-generated destructor stub
	}

	void SerialMidiDecoder::getNextByte()
	{
		this->newByte(this->buffer->pop());
	}

}

