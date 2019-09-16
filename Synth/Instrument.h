/*
 * Instrument.h
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include "SystemCommon.h"
#include "Voice.h"
#include "VirtualPatch.h"
namespace glock
{

	enum AssignerVoiceState
	{
		
		ASSIGNER_VOICE_FREE,
		ASSIGNER_VOICE_OWNED,
		ASSIGNER_VOICE_OWNED_RELEASE,
		ASSIGNER_VOICE_RELEASE,
		ASSIGNER_VOICE_NONE,
	};

	class Instrument {
	public:
		Instrument();
		virtual ~Instrument();
		void Init(Voice *t_voices, int t_samplerate);
		void noteOn(char t_note, char t_velocity);
		void noteOff(char t_note);

	private:
		struct VirtualPatch patch;
		Voice *voices[MAX_VOICES];
		int m_voiceCount;
		char m_activeVoices[MAX_VOICES];
	};
}
#endif /* INSTRUMENT_H_ */
