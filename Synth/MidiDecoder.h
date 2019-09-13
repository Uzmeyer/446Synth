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







class MidiDecoder {
public:
	MidiDecoder();
	MidiDecoder(Synth* synth);
	virtual ~MidiDecoder();
	void Init(Synth* synth);
	void setSynth(Synth* synthesizer);
	void newByte(unsigned char byte);
	void newMessage(MidiEvent message);
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
	Synth* synth;
};



#endif /* SRC_MIDIDECODER_H_ */
