/*
 * Instrument.cpp
 *
 *  Created on: 10.09.2019
 *      Author: Jakob
 */

#include "Instrument.h"

namespace glock
{
	Instrument::Instrument() {
		// TODO Auto-generated constructor stub

	}
	Instrument::~Instrument() {
		// TODO Auto-generated destructor stub
	}

	void Instrument::Init(Voice *t_voices, int t_samplerate)
	{
		for (int i = 0; i < MAX_VOICES; i++)
		{
			voices[i] = &t_voices[i];

		}
		
	}

	void Instrument::noteOn(char note, char velocity)
	{	//assigner needs to assign voices fast and following a system
		//rules: 
		//can't play a voice currently played by another Instrument
		//can take over decaying voice of other instrument?
		//
		//priorities:
		//1 retrigger already playing voice of same note, two voices with same instrument and notes will break the system
		//2 use unused voice
		//3 reuse releasing voice from this instrument
		//4 reuse releasing voice from other instrument?
		//5 don't play note
		//TODO maybe queue note
		//TODO probaply optimize this shit
		int foundVoice = -1;
		int foundVoiceType = ASSIGNER_VOICE_NONE;
		for (int i = 0; i < MAX_VOICES; i++)
		{
			int voiceState = voices[i]->getState();
			if (voices[i]->getCurrentInstrument() == this)
			{
				
				if (voices[i]->getNote() == note && voiceState > VOICE_STATE_OFF) //1 retrigger already playing voice of same note, doing some enum math is maybe not the best idea but should work (hopefully)
				{
					voices[i]->noteRestart(note, velocity); //retrigger and get out of here, we are done :D
					return;
				}

				if (voiceState == VOICE_STATE_RELEASED && foundVoiceType > ASSIGNER_VOICE_FREE) //a released voice of this Instrument is a decent candidate, might as well check this here, also more dumb enum math yay
				{
					foundVoice = i;
					foundVoiceType = ASSIGNER_VOICE_OWNED_RELEASE;
					continue;	//we can be sure that this voice isn't free so this is the next highest priority, this saves two checks
				}
			}

			if (voiceState == VOICE_STATE_OFF)	//a free voice has priority over others, so we just overwrite without checking what we currently have. 
			{									//this means voices will tend to populate from highest index first, wich doesn't really matter since we need to check everything anyway
				foundVoice = i;
				foundVoiceType = ASSIGNER_VOICE_FREE;
				continue;	//only trash after this
			}

			if (voiceState == VOICE_STATE_RELEASED && foundVoiceType >= ASSIGNER_VOICE_RELEASE) // can only get a releasing voice of a different instrument. everything else viable would have already continued
			{
				foundVoice = i;
				foundVoiceType = ASSIGNER_VOICE_RELEASE;
			}
									
		}
		switch (foundVoiceType)
		{
		case ASSIGNER_VOICE_FREE: //TODO just noteOn right now, probaply handle cases better later
		{
			voices[foundVoice]->noteOn(note, velocity, this);
			break;
		}
		case ASSIGNER_VOICE_OWNED_RELEASE:
		{
			voices[foundVoice]->noteRestart(note, velocity);
		}
		case ASSIGNER_VOICE_RELEASE:
		{
			voices[foundVoice]->noteRestart(note, velocity, this);
		}
		default: //welp, nothing found, nothing we can do for now ¯\_(ツ)_/¯
			break;
		}


	}

	void Instrument::noteOff(char note)
	{
		for (int i = 0; i < MAX_VOICES; i++)
		{
			if (voices[i]->getNote() == note && voices[i]->getCurrentInstrument() == this)
			{
				voices[i]->noteOff();
			}
		}
	}
}
