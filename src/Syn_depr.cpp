#include "../include/Synapse.h"

void Synapse::depr(){

	double temp = Random();
	if (efficacy == 1){
		if (state == 0){
			if (temp < q[0])
				efficacy = 0;
		}else{
			if (temp < p[state-1]){
				state = state -1;
			}else{
				if (temp < q[state]){
					efficacy = 0;
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
