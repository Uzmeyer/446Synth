/*
 * VirtualPatch.h
 *
 *  Created on: 09.09.2019
 *      Author: Jakob
 */

#ifndef VIRTUALPATCH_H_
#define VIRTUALPATCH_H_

#include <stdint.h>
namespace glock
{
	enum SynthType
	{
		SYNTHTYPE_ANALOG = 0,
		SYNTHTYPE_HAMMOND = 1
	};

	struct OscillatorParameters
	{
		char octave;
		char semiSteps;
		float detune;
		char waveform;
		char type;
	};

	struct EnvelopeParameters
	{
		float attack;
		float decay;
		float sustain;
		float release;
	};

	struct FilterParameters
	{

	};

	struct LfoParameters
	{

	};

	struct AnalogPatch
	{
		const uint8_t type = SYNTHTYPE_ANALOG;
		OscillatorParameters osc1;
		OscillatorParameters osc2;
		OscillatorParameters osc3;
		OscillatorParameters osc4;
		EnvelopeParameters env1;
		EnvelopeParameters env2;
		EnvelopeParameters env3;
		EnvelopeParameters env4;
		FilterParameters flt1;
		FilterParameters flt2;
		LfoParameters lfo1;
		LfoParameters lfo2;
	};

	struct HammondPatch
	{
		const uint8_t type = SYNTHTYPE_HAMMOND;
	};


	struct VirtualPatch
	{
		char patchName[16];
		uint8_t synthtype;
		AnalogPatch analog;
		HammondPatch hammond;


	};


	extern VirtualPatch defaultPatch;

}
#endif /* VIRTUALPATCH_H_ */
