/*
 * Wavetable.h
 *
 *  Created on: 08.09.2019
 *      Author: Jakob
 */

#ifndef WAVETABLE_H_
#define WAVETABLE_H_
namespace glock
{
	enum WAVETABLE
	{
		WAVETABLE_SINE = 0,
		WAVETABLE_BLSQR = 1,
		WAVETABLE_BLSAW = 2,
		WAVETABLE_BLTRI = 3,
		WAVETABLE_BLTRAP = 4,
		WAVETABLE_SQR = 5,
		WAVETABLE_SAW = 6,
		WAVETABLE_TRI = 7,

	};
	struct Wavetable
	{
		int len;
		float* table;
	};

	extern float sinTable[];

	//http://www.till.com/articles/QuadTrapVCO/trapezoid.html
	//https://lpsa.swarthmore.edu/Fourier/Series/ExFS.html#OddSawtooth

	extern float harmonicSqrTable[];
	extern float sqrTable[];
	extern float harmonicTriTable[];
	extern float triTable[];
	extern float harmonicTrapTable[];
	extern float harmonicSawTable[];
	extern float sawTable[];

}

#endif /* WAVETABLE_H_ */