/*
 * Filter.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "SynthComponent.h"
namespace glock
{
	class Filter : public SynthComponent {
	public:
		Filter();
		virtual ~Filter();
	};
}
#endif /* FILTER_H_ */
