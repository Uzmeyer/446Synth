/*
 * TimedSynthComponent.h
 *
 *  Created on: 27.05.2019
 *      Author: Jakob
 */

#ifndef TIMEDSYNTHCOMPONENT_H_
#define TIMEDSYNTHCOMPONENT_H_

#include <SynthComponent.h>

class TimedSynthComponent: public SynthComponent {
public:
	TimedSynthComponent();
	virtual ~TimedSynthComponent();
	float run();
	

};

#endif /* TIMEDSYNTHCOMPONENT_H_ */
