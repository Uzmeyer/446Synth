/*
 * SynthComponent.h
 *
 *  Created on: 18.05.2019
 *      Author: Jakob
 */

#ifndef SYNTHCOMPONENT_H_
#define SYNTHCOMPONENT_H_

#include <stdint.h>


class SynthComponent {
public:
	SynthComponent();
	virtual ~SynthComponent();
	float getCurrentValue();

protected:
	float currentValue = 0.0f;
};



#endif /* SYNTHCOMPONENT_H_ */
