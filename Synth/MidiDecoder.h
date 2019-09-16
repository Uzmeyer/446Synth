/*
 * MidiDecoder.h
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#ifndef SRC_MIDIDECODER_H_
#define SRC_MIDIDECODER_H_

#include "Midi.h"
#include "Synth.h"




namespace glock
{
	


	class MidiDecoder {
	public:
		MidiDecoder();
		MidiDecoder(Synth* synth);
		virtual ~MidiDecoder();
		void Init(Synth* synth);
		void setSynth(Synth* synth);
		void newByte(unsigned char byte);
		void newMessage(MidiMessage message);
		void noteOn();
		void noteOff();
		void allNotesOff();
		void polyAftertouch();
		void controlChange();
		void programChange();
		void channelAftertouch();
		void pitchBend();
		void sysEx();

	private:
		Synth* m_synth;
		char m_basicChannel = MIDI_CHANNEL_1;
		char m_instrumentChannel[MAX_INSTRUMENTS];
	};

}

#endif /* SRC_MIDIDECODER_H_ */
