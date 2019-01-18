#include "../include/LIFNeuron.h"


void LIFNeuron::evolution(double t, double dt, double Iout){
	double F1 = dt * ( ((vrest - voltage)/memtime) + Iout );
	double F2 = dt * ( ((vrest - (voltage+F1) )/memtime ) + Iout );
	voltage+=(F1+F2)/2.0;

	if (voltage > vth){
		state = true;
		spikecount++;
		spiketime = t;
		//recordspike(t);
		voltage = vrest;
		} else {
			state = false;
			}
}

