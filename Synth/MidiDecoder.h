/*
 * MidiDecoder.h
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#ifndef SRC_MIDIDECODER_H_
#define SRC_MIDIDECODER_H_

#include "Synth.h"



enum MidiMessageType
{
	MIDI_NOTE_OFF = 0x80,
	MIDI_NOTE_NOTEON = 0x90,
	MIDI_NOTE_POLY_PRESSURE = 0xA0, //poly aftertouch
	MIDI_CONTROL_CHNAGE = 0xB0,
	MIDI_PROGRAM_CHANGE = 0xC0, //program change, only one command byte
	MIDI_CHANNEL_PRESSURE = 0xD0, //channel aftertouch, only one command byte
	MIDI_PITCHBEND = 0xE0,
	MIDI_SYSTEM = 0xF0
};

struct MidiMessage
{
	unsigned char messagetype;
	unsigned char channel;
	unsigned char data[2]
};



class MidiDecoder {
public:
	MidiDecoder(Synth* synth);
	virtual ~MidiDecoder();
	void setSynth(Synth* synth);
	void newByte(unsigned char byte);
	void newMessage(MidiMessage message);

private:
	Synth* synth;
};



#endif /* SRC_MIDIDECODER_H_ */
