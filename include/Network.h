#include "ALL.h"
#include "LIFNeuron.h"
#include "Synapse.h"
#include "SupSynapse.h"


class Network{

	private:
		int nd;
		int ns; 
		//vector<LIFNeuron> ngred;
		//vector<LIFNeuron> nggr;
		//vector<Synapse> metared;
		//vector<Synapse> metagr;
		//vector<SupSynapse> denred;
		//vector<SupSynapse> dengr;
		LIFNeuron neuron;
		SupSynapse* dendrites;
		Synapse* synapses;
		double** conn;
		
	public:
		Network(){
			nd=3;
			ns=300;
			//cout << "nd:" << nd << endl;	
			dendrites = new SupSynapse[nd];
			synapses = new Synapse[ns];
			//conn.resize(nd);
			//for (int i=0; i<nd; i++)
			//	conn[i].resize(ns/nd);
			
			conn = new double*[nd];
			for (int i=0; i<nd; i++)
				conn[i] = new double[ns];
			
			float min = 0.1;
			float max = 1.0;
			//cout << "\n ############# Connection: ############\n";	
			for (int i=0; i<nd; i++){
				//vector<int> temp;
				for (int j=0; j<ns; j++){
					//temp.push_back(Random(0.5,3));
					conn[i][j]=Random(min,max);
					//cout << conn[i][j] << "," ;
				}
				//cout << endl;
				//conn.push_back(temp);
			}
			
			/*
			cout << "\n ############# Synapses: ############\n";	
			for (int i=0; i<ns; i++)
				cout << synapses[i].g() << ", ";
			
			cout << "\n ############# SupSynapses: ############\n";	
			for (int i=0; i<nd; i++)
				cout << dendrites[i].g() << ", ";	
			*/
			double* dg = new double[nd];
			dg[0] = 1.5;
			dg[1] = 1.5;
			dg[2] = 1.5;
			double Iout=0.0;
			cout << "\n#############The Info to be debuged############3\n";
			cout << setw(10) << "nd" <<
					setw(10) << "ns" << 
					setw(10) << "dg" <<
					setw(10) << "de" << 
					setw(10) << "sg" <<
					setw(10) << "se" <<
					setw(10) << "te" <<
					setw(10) << "Iout" << endl;
			for (int i=0; i<nd; i++){
				for (int j=0; j<(ns/nd); j++){
					double te = dg[i] * dendrites[i].g() * conn[i][j] * synapses[i*(ns/nd)+j].g();
					Iout += te;
					cout << setw(10) << i << 
							setw(10) << j <<
							setw(10) << dg[i] <<
							setw(10) << dendrites[i].g() << 
							setw(10) << conn[i][j] <<
							setw(10) << synapses[i*(ns/nd)+j].g() <<
							setw(10) << te <<
							setw(10) << Iout << endl;
				}
			}
			
		}
		
		
		void evolve(double t, double dt);
		double neuronv(){return neuron.returnv();}
};
