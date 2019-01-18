#include "../include/SupSynapse.h"

void SupSynapse::poten(){
	double temp = Random();
	if (temp < alpha[state]){
		if (efficacy == 0)
			efficacy = 1;
	}
}
