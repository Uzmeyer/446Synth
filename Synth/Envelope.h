/*
 * Envelope.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef ENVELOPE_H_
#define ENVELOPE_H_

#include "TimedSynthComponent.h"
namespace glock {

	extern const float expAttackTable[];
#define EXPATABLELEN 63 //onle less for interpolation

	enum EnvelopeState
	{
		ENVELOPE_STATE_A = 0,
		ENVELOPE_STATE_D,
		ENVELOPE_STATE_S,
		ENVELOPE_STATE_R,
		ENVELOPE_STATE_OFF,
		ENVELOPE_NUM_STATES
	};

	enum EnvelopeMode
	{
		ENVELOPE_MODE_LIN = 0,
		ENVELOPE_MODE_EXP
	};

	class Envelope : public TimedSynthComponent {
	public:
		Envelope();
		virtual ~Envelope();
		void init(int t_samplerate);
		void updatePhaseIncs();
		void noteOn();
		void noteOff();
		inline void newState()
		{
			switch (m_currentState)
			{
			case ENVELOPE_STATE_A:
			{
				m_currentState = ENVELOPE_STATE_D;
				currentValue = 1.0f;
				m_targetValue = m_sustain;
				m_phaseInc = m_decayInc;
				break;
			}
			case ENVELOPE_STATE_D:
			{
				m_currentState = ENVELOPE_STATE_S;
				currentValue = m_sustain;
				m_targetValue = m_sustain;
				m_phaseInc = 0.0f;
				break;
			}
			case ENVELOPE_STATE_S:
			{
				m_currentState = ENVELOPE_STATE_R;
				currentValue = m_sustain;
				m_targetValue = 0.0f;
				m_phaseInc = m_releaseInc;
				break;
			}
			case ENVELOPE_STATE_R:
			{
				m_currentState = ENVELOPE_STATE_OFF;
				currentValue = 0.0f;
				m_targetValue = 0.0f;
				m_phaseInc = 0.0f;
				break;
			}
			}
			m_phase = 0.0f;
			m_previousStateValue = currentValue;
			m_valueDifference = m_targetValue - m_previousStateValue;
		};

		inline float run()
		{
			m_phase += m_phaseInc; //increment before calculation to save calculation in case of rollover
			if (m_phase >= 1.0)
			{
				newState();
				return currentValue;
			}

			if (m_currentMode) //ENVELOPE_MODE_EXP = 1
			{
				float temp = m_phase * EXPATABLELEN; //get index as float
				int intPart = (int)temp;
				float fracPart = temp - intPart;
				float sample0 = expAttackTable[intPart]; //get lower sample
				float sample1 = expAttackTable[intPart + 1]; //get higher sample
				temp = sample0 + (sample1 - sample0) * fracPart; //yes, reusing variables is not smart
				currentValue = temp * m_valueDifference + m_previousStateValue; //scale and move to current needed output range, exp direction is switched by negative difference
			}
			else
			{
				currentValue = m_phase * m_valueDifference + m_previousStateValue; //almost trivial
			}
			return currentValue;
		};
		EnvelopeState getState();

	private:
		EnvelopeState m_currentState;
		EnvelopeMode m_currentMode;
		float m_attack;
		float m_decay;
		float m_sustain;
		float m_release;
		float m_attackInc;
		float m_decayInc;
		float m_releaseInc;
		float m_phase;
		float m_phaseInc;
		float m_previousStateValue;
		float m_targetValue;
		float m_valueDifference;
		static float m_envIncTable[1271];
		static bool m_init;
	};
}
#endif /* ENVELOPE_H_ */

