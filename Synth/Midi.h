/*
 * Midi.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef MIDI_H_
#define MIDI_H_
namespace glock
{
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

	enum MidiControlChange
	{
		MIDI_CC_ALL_SOUND_OFF = 120,
		MIDI_CC_RESET_ALL_CONTROLLERS = 121,
		MIDI_CC_LOCAL_CONTROL = 122,
		MIDI_CC_ALL_NOTES_OFF = 123,
	};

	enum MidiChannel
	{
		MIDI_CHANNEL_1 = 0,
		MIDI_CHANNEL_2,
		MIDI_CHANNEL_3,
		MIDI_CHANNEL_4,
		MIDI_CHANNEL_5,
		MIDI_CHANNEL_6,
		MIDI_CHANNEL_7,
		MIDI_CHANNEL_8,
		MIDI_CHANNEL_9,
		MIDI_CHANNEL_10,
		MIDI_CHANNEL_11,
		MIDI_CHANNEL_12,
		MIDI_CHANNEL_13,
		MIDI_CHANNEL_14,
		MIDI_CHANNEL_15,
		MIDI_CHANNEL_16,
		MIDI_CHANNEL_OMNI
	};

	struct MidiMessage
	{
		unsigned char messagetype;
		unsigned char channel;
		unsigned char data[2];
	};

	const float midiMaxInv = 1.0f/127.0f;


}
#endif /* MIDI_H_ */
