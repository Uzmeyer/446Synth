/*
 * MidiDecoder.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#include "MidiDecoder.h"

namespace glock
{


	MidiDecoder::MidiDecoder()
	{
		this->m_synth = nullptr;
		for (int i = 0; i < MAX_INSTRUMENTS; i++)
		{
			m_instrumentChannel[i] = i;
		}
	}

	MidiDecoder::MidiDecoder(Synth* synth) : m_synth(synth)
	{

	}

	MidiDecoder::~MidiDecoder() {
		// TODO Auto-generated destructor stub
	}

	void MidiDecoder::Init(Synth* synth)
	{
		this->setSynth(synth);
	}

	void MidiDecoder::setSynth(Synth* synth)
	{
		this->m_synth = synth;
	}

	void MidiDecoder::newByte(unsigned char byte)
	{

	}


	void MidiDecoder::newMessage(MidiMessage message)
	{
		int instrumentIndex = 0;
		int listeningInstruments[MAX_INSTRUMENTS];
		if (message.messagetype == MIDI_SYSTEM) // system commom messages use channel for identifier
		{
			//TODO handle system messages here
			return;
		}
		else
		{
			for (int i = 0; i < MAX_INSTRUMENTS; i++) //check wich instruments are listening to the incoming channel
			{
				if (m_instrumentChannel[i] == message.channel || m_instrumentChannel[i] == MIDI_CHANNEL_OMNI)
				{
					listeningInstruments[instrumentIndex] = i;
					instrumentIndex++;
				}
			}
		}
		
		if (instrumentIndex == 0 && message.channel != m_basicChannel) //nothing that interests us
		{
			return;
		}

		switch (message.messagetype)
		{
		case MIDI_NOTE_ON:
		{
			for (int i = 0; i < instrumentIndex; i++)
			{
				m_synth->noteOn(listeningInstruments[i], message.data[0], message.data[1]);
			}
			break;
		}
		case MIDI_NOTE_OFF:
		{
			for (int i = 0; i < instrumentIndex; i++)
			{
				m_synth->noteOff(instrumentIndex, message.data[0]);
			}
			break;
		}
		case MIDI_NOTE_POLY_PRESSURE:
		{

		}
		case MIDI_CONTROL_CHANGE:
		{

		}
		case MIDI_PROGRAM_CHANGE:
		{

		}
		case MIDI_CHANNEL_PRESSURE:
		{

		}
		case MIDI_PITCHBEND:
		{

		}
		
		}
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

}