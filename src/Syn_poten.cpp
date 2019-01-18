#include "../include/Synapse.h"

void Synapse::poten(){

	double temp = Random();
	if (efficacy == 0){
		if (state == 0){
			if (temp < q[0])
				efficacy = 1;
		}else{
			if (temp < p[state-1]){
				state = state -1;
			}else{
				if (temp < q[state]){
					efficacy = 1;
					state = 0;
				}
			}
		}
	}else{
		if (state < m-1){
			if (temp < p[state]){
				state = state + 1;
			}
		}
	}
}
