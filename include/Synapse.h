#include "ALL.h"


class Synapse {
	private:
		int efficacy;
		int state;
		int m;
		double* q;
		double* p;
	public:
		Synapse(){
			m = 4;
			q = new double[m];
			p = new double[m-1];
			q[0]=0.4;
			p[0]=0.3;
			for (int i=1; i<4; i++)
				q[i] = pow(q[0], double((i+1)*(m-2)+1)/(m-1) );
			for (int i=1; i<3; i++)
				p[i] = ipow(p[0],i);
			efficacy = Random(2);
			//cout << "efficacy: " << efficacy << ", ";
			state = Random(4);
			//for (int i=0; i<4; i++)
			//cout << "q[" << i << "]:\t" << q[i] << endl;
			//cout << "Meta Syn Efficacy:\t" << efficacy << endl;
		}
		
		void poten();
		void depr();
		int g(){return efficacy;};
};
