/*
 * Midi.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef MIDI_H_
#define MIDI_H_

enum MidiMessageType
{
	MIDI_NOTE_OFF = 0x80,
	MIDI_NOTE_ON = 0x90,
	MIDI_NOTE_POLY_PRESSURE = 0xA0, //poly aftertouch
	MIDI_CONTROL_CHANGE = 0xB0,
	MIDI_PROGRAM_CHANGE = 0xC0, //program change, only one command byte
	MIDI_CHANNEL_PRESSURE = 0xD0, //channel aftertouch, only one command byte
	MIDI_PITCHBEND = 0xE0,
	MIDI_SYSTEM = 0xF0
};

struct MidiEvent
{
	unsigned char messagetype;
	unsigned char channel;
	unsigned char data[2];
};

extern float frequency[];



#endif /* MIDI_H_ */
