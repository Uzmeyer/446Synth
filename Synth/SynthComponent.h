/*
 * SynthComponent.h
 *
 *  Created on: 18.05.2019
 *      Author: Jakob
 */

#ifndef SYNTHCOMPONENT_H_
#define SYNTHCOMPONENT_H_



class SynthComponent {
public:
	SynthComponent();
	virtual ~SynthComponent();
	virtual float out() = 0;
};



#endif /* SYNTHCOMPONENT_H_ */
