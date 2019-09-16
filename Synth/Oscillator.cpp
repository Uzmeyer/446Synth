/*
 * Oscillator.cpp
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#include "Oscillator.h"

namespace glock
{
	float Oscillator::m_freqIncTable[128];
	bool Oscillator::m_init;

	Oscillator::Oscillator() {
		// TODO Auto-generated constructor stub
		m_oscOn = false;
		m_wavetable = &wavetables[WAVETABLE_TRI];
	}

	Oscillator::~Oscillator() {
		// TODO Auto-generated destructor stub
	}

	void Oscillator::initFreqIncTab(int samplerate)
	{
		if (!m_init)
		{
			float samplerateInv = 1.0f / (float) samplerate;
			for (int i = 0; i < 128; i++)
			{
				m_freqIncTable[i] = midiFrequencies[i] * samplerateInv;
			}
			m_init = true;
		}
		
	}

	void Oscillator::start()
	{
		m_oscOn = true;
	}

	void Oscillator::stop()
	{
		m_oscOn = false;
	}

	void Oscillator::setNote(char t_note)
	{
		m_phaseInc = m_freqIncTable[t_note];
	}



	float Oscillator::getCurrentValue()
	{
		return this->currentValue;
	}

	void Oscillator::reset()
	{
		m_phase = 0.0f;
	}

}