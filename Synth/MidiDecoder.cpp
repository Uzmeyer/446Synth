/*
 * MidiDecoder.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#include "MidiDecoder.h"



MidiDecoder::MidiDecoder(Synth* synth) {
	this->synth = synth;

}

MidiDecoder::~MidiDecoder() {
	// TODO Auto-generated destructor stub
}

void MidiDecoder::setSynth(Synth* synth)
{
	this->synth = synth;
}

void MidiDecoder::newByte(unsigned char byte)
{

}

void newMessage(MidiMessage message)
{

}
