#include "ALL.h"


class SupSynapse {
	private:
		int efficacy;
		int state;
		int m;
		//vector<double> q;
		//vector<double> p;
		double* alpha;
	public:
		SupSynapse(){
			m = 4;
			alpha = new double [m];
			//q.push_back(0.4);
			//p.push_back(0.3);
			for (int i=1; i<m+1; i++)
				alpha[i-1] = ipow(0.2,i);
			//for (int i=1; i<m-1; i++)
			//	p.push_back(ipow(p[0],i));
			efficacy = Random(2);
			state = Random(m);
			//for (int i=0; i<4; i++)
			//	cout << "q[" << i << "]:\t" << q[i] << endl;
			//cout << "SupSyn Efficacy:\t" << efficacy << endl;
		}
		
		void poten();
		void depr();
		int g(){return efficacy;};
};
