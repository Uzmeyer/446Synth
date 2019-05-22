/*
 * MidiDecoder.h
 *
 *  Created on: 04.05.2019
 *      Author: Jakob
 */

#ifndef SRC_MIDIDECODER_H_
#define SRC_MIDIDECODER_H_

#include "Synth.h"

namespace std {

class MidiDecoder {
public:
	MidiDecoder(Synth* synth);
	virtual ~MidiDecoder();
	virtual void getNextByte() = 0;
	void setSynth(Synth* synth);
	void newByte(unsigned char byte);

private:
	Synth* synth;
};

} /* namespace std */

#endif /* SRC_MIDIDECODER_H_ */
