/*
 * MidiDecoder.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#include "MidiDecoder.h"



MidiDecoder::MidiDecoder()
{
	this->synth = nullptr;
}

MidiDecoder::MidiDecoder(Synth* synthesizer) {
	this->synth = synthesizer;

}

MidiDecoder::~MidiDecoder() {
	// TODO Auto-generated destructor stub
}

void MidiDecoder::Init(Synth* synthesizer)
{
	this->setSynth(synthesizer);
}

void MidiDecoder::setSynth(Synth* synthesizer)
{
	this->synth = synthesizer;
}

void MidiDecoder::newByte(unsigned char byte)
{

}


void MidiDecoder::newMessage(MidiEvent message)
{

}

void MidiDecoder::noteOn()
{

}

void MidiDecoder::noteOff()
{
}

void MidiDecoder::allNotesOff()
{
}

void MidiDecoder::polyAftertouch()
{
}

void MidiDecoder::controlChange()
{
}

void MidiDecoder::programChange()
{
}

void MidiDecoder::channelAftertouch()
{
}

void MidiDecoder::pitchBend()
{
}

void MidiDecoder::sysEx()
{
}

