/*
 * Midi.cpp
 *
 *  Created on: 09.09.2019
 *      Author: Jakob
 */

float frequency[] = {		//http://subsynth.sourceforge.net/midinote2freq.html
	8.17579936981201171875f,	8.661956787109375f,			9.17702388763427734375f,	9.72271823883056640625f,	10.300861358642578125f,
	10.91338253021240234375f,	11.56232547760009765625f,	12.2498569488525390625f,	12.978271484375f,			13.75f,
	14.5676174163818359375f,	15.4338531494140625f,		16.3515987396240234375f,	17.32391357421875f,			18.3540477752685546875f,
	19.4454364776611328125f,	20.60172271728515625f,		21.8267650604248046875f,	23.1246509552001953125f,	24.499713897705078125f,
	25.95654296875f,			27.5f,						29.135234832763671875f,		30.867706298828125f,		32.703197479248046875f,
	34.6478271484375f,			36.708095550537109375f,		38.890872955322265625f,		41.2034454345703125f,		43.653530120849609375f,
	46.249301910400390625f,		48.99942779541015625f,		51.9130859375f,				55.0f,						58.27046966552734375f,
	61.73541259765625f,			65.40639495849609375f,		69.295654296875f,			73.41619110107421875f,		77.78174591064453125f,
	82.406890869140625f,		87.30706024169921875f,		92.49860382080078125f,		97.9988555908203125f,		103.826171875f,
	110.0f,						116.5409393310546875f,		123.4708251953125f,			130.8127899169921875f,		138.59130859375f,
	146.8323822021484375f,		155.5634918212890625f,		164.81378173828125f,		174.6141204833984375f,		184.9972076416015625f,
	195.997711181640625f,		207.65234375f,				220.0f,						233.081878662109375f,		246.941650390625f,
	261.625579833984375f,		277.1826171875f,			293.664764404296875f,		311.126983642578125f,		329.6275634765625f,
	349.228240966796875f,		369.994415283203125f,		391.99542236328125f,		415.3046875f,				440.0f,
	466.16375732421875f,		493.88330078125f,			523.25115966796875f,		554.365234375f,				587.32952880859375f,
	622.25396728515625f,		659.255126953125f,			698.45648193359375f,		739.98883056640625f,		783.9908447265625f,
	830.609375f,				880.0f,						932.3275146484375f,			987.7666015625f,			1046.5023193359375f,
	1108.73046875f,				1174.6590576171875f,		1244.5079345703125f,		1318.51025390625f,			1396.9129638671875f,
	1479.9776611328125f,		1567.981689453125f,			1661.21875f,				1760.0f,					1864.655029296875f,
	1975.533203125f,			2093.004638671875f,			2217.4609375f,				2349.318115234375f,			2489.015869140625f,
	2637.0205078125f,			2793.825927734375f,			2959.955322265625f,			3135.96337890625f,			3322.4375f,
	3520.0f,					3729.31005859375f,			3951.06640625f,				4186.00927734375f,			4434.921875f,
	4698.63623046875f,			4978.03173828125f,			5274.041015625f,			5587.65185546875f,			5919.91064453125f,
	6271.9267578125f,			6644.875f,					7040.0f,					7458.6201171875f,			7902.1328125f,
	8372.0185546875f,			8869.84375f,				9397.2724609375f,			9956.0634765625f,			10548.08203125f,
	11175.3037109375f,			11839.8212890625f,			12543.853515625f
};



