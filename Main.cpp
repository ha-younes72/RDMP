#include "./include/Network.h"
//#include "./include/random.h"
//#include <stdio.h>
//#include <cstdio>
//#include <fstream>

//using namespace std;

int main(){
	Randomize();
	/*LIFNeuron node;
	vector<double> V;
	ofstream fout("data/outv.txt");
	double Iout = 10;
	for (int i=0; i<1000; i++){
		node.evolution(i*0.05, 0.05, Iout );
		fout << i*0.05 << "\t" << node.returnv() << endl;
		V.push_back(node.returnv());
	}
	
	Synapse syn;
	SupSynapse ssyn;
	//cout << "This is test:" << node.returnstate() << endl;
	*/
	ofstream fout("data/V.txt");
	Network net;
	double dt = 0.05;
	for (double t=0; t<10; t+=dt){
		//cout << "t: " << t << endl;
		net.evolve(t,dt);
		fout << t << '\t' << net.neuronv() << endl;
	}
	cout << "Done!!!!!!!!!\n";
	//fout.close();
	return 0;
}
