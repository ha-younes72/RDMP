#include "../include/Network.h"


void Network::evolve(double t, double dt){
	//vector<double> dg;
	//dg.push_back(2);
	//dg.push_back(2);
	//dg.push_back(2);
	double* dg = new double[nd];
	dg[0] = 1.2;
	dg[1] = 1.2;
	dg[2] = 1.2;
	double Iout=0.0;
	//cout << "nd:" << nd << endl;
	//cout << "Size\t" << conn.size() << endl;		
	for (int i=0; i<nd; i++){
		for (int j=0; j<(ns/nd); j++){
			//cout << "i:\t" << i << endl;
			//cout << "dg[" << i << "]:\t" << dg[i] << endl;
			//cout << "dendrites[" << i << "]:\t" << dendrites[i].g() << endl;
			//cout << "dffdf\n";
			//cout << "conn[" << i << "]:\t" << conn[i][j] << endl;
			//cout << "synapses[" << i*(ns/nd)+j << "]:\t" << synapses[i*(ns/nd)+j].g() << endl;
			double te = dg[i] * dendrites[i].g() * conn[i][j]* synapses[i*(ns/nd)+j].g();
			//cout << te << ",";
			Iout += te;
		}
	}
	cout << "Iout:\t" << Iout << endl;
	neuron.evolution(t, dt, Iout);
}
