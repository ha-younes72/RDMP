#include "../include/SupSynapse.h"

void SupSynapse::depr(){

	double temp = Random();
	if (temp < alpha[state]){
		if (efficacy == 1)
			efficacy = 0;
	}
	
}
