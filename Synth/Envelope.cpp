/*
 * Envelope.cpp
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */


#include "Envelope.h"
namespace glock {
	const float expAttackTable[] = {
		0.0f, 0.0617916584014892578125f, 0.119839608669281005859375f, 0.1743705272674560546875f,
		0.225597679615020751953125f, 0.27372109889984130859375f, 0.318928778171539306640625f, 0.36139762401580810546875f,
		0.401293277740478515625f, 0.43877184391021728515625f, 0.4739797115325927734375f, 0.507054388523101806640625f,
		0.538125216960906982421875f, 0.56731355190277099609375f, 0.594733417034149169921875f, 0.620492041110992431640625f,
		0.644690036773681640625f, 0.66742193698883056640625f, 0.688776493072509765625f, 0.70883738994598388671875f,
		0.72768270969390869140625f, 0.7453863620758056640625f, 0.76201736927032470703125f, 0.777640759944915771484375f,
		0.792317569255828857421875f, 0.806105136871337890625f, 0.819057404994964599609375f, 0.831224918365478515625f,
		0.842655181884765625f, 0.853393018245697021484375f, 0.86348021030426025390625f, 0.87295627593994140625f,
		0.88185822963714599609375f, 0.890220820903778076171875f, 0.8980767726898193359375f, 0.905456721782684326171875f,
		0.9123895168304443359375f, 0.918902337551116943359375f, 0.925020515918731689453125f, 0.930768072605133056640625f,
		0.93616735935211181640625f, 0.941239535808563232421875f, 0.946004390716552734375f, 0.95048058032989501953125f,
		0.95468556880950927734375f, 0.958635747432708740234375f, 0.962346613407135009765625f, 0.96583271026611328125f,
		0.96910750865936279296875f, 0.9721839427947998046875f, 0.975073993206024169921875f, 0.9777889251708984375f,
		0.980339348316192626953125f, 0.98273527622222900390625f, 0.9849860668182373046875f, 0.987100422382354736328125f,
		0.98908674716949462890625f, 0.990952670574188232421875f, 0.9927055835723876953125f, 0.994352281093597412109375f,
		0.995899200439453125f, 0.997352421283721923828125f, 0.9987175464630126953125f, 1.0f,

	};

	float Envelope::m_envIncTable[1271];
	bool Envelope::m_init;

	Envelope::Envelope() {
		// TODO Auto-generated constructor stub
		m_attack = 1.0f;
		m_decay = 1.0f;
		m_release = 2.0f;
		m_sustain = 0.5f;
		m_currentState = ENVELOPE_STATE_OFF;
		m_currentMode = ENVELOPE_MODE_EXP;
		m_phase = 0.0f;
		m_phaseInc = 0.0f;
		m_previousStateValue = 0.0f;
		m_targetValue = 0.0f;
		m_valueDifference = 0.0f;
		updatePhaseIncs();
	}

	Envelope::~Envelope() {
		// TODO Auto-generated destructor stub
	}

	void Envelope::init(int t_samplerate)
	{
		if (!m_init)
		{
			for (int i = 1; i < 1271; i++)
			{
				m_envIncTable[i] = 1.0f / (t_samplerate * (i / 100.0f));
			}
			m_envIncTable[0] = 1.0f / (t_samplerate * (1 / 1000.0f));
			m_init = true;
		}
	}

	void Envelope::updatePhaseIncs()
	{
		if (m_sustain > 1.0f)
		{
			m_sustain = 1.0f;
		}
		else if (m_sustain < 0.0f)
		{
			m_sustain = 0.0f;
		}
		m_attackInc = m_envIncTable[((int) (m_attack * 100.0f)) % 1271];
		m_decayInc = m_envIncTable[((int)(m_decay * 100.0f)) % 1271];
		m_releaseInc = m_envIncTable[((int)(m_release * 100.0f)) % 1271];
	}

	void Envelope::noteOn()
	{
		m_phase = 0.0f;
		m_phaseInc = m_attackInc;
		m_targetValue = 1.0f;
		m_currentState = ENVELOPE_STATE_A;
		m_previousStateValue = currentValue;
		m_valueDifference = m_targetValue - m_previousStateValue;
	}

	void Envelope::noteOff()
	{
		m_currentState = ENVELOPE_STATE_R;
		m_targetValue = 0.0f;
		m_phaseInc = m_releaseInc;
		m_phase = 0.0f;
		m_previousStateValue = currentValue;
		m_valueDifference = m_targetValue - m_previousStateValue;
	}

	EnvelopeState Envelope::getState()
	{
		return m_currentState;
	}


} //namespace