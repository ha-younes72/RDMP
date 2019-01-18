#include "ALL.h"

class LIFNeuron {
	private:
		double memtime;		//membrane time constant(mS)
		double voltage;         //(mV)
		double vrest;		//(mV)
		double vth;		//(mV)
		//vector<double> spiketime;	//(mS)
		double spiketime;
		int spikecount;
		//int mode;
		bool state;		//true means neuron spike, and false means neuron is off
	public:
		LIFNeuron(double mtime, double rest, double th){
			memtime = mtime; voltage = rest; vrest = rest; vth = th; state = false;
			spikecount = 1;
			//spiketime = new double[100000];
			}
		LIFNeuron(){
			memtime = 20.0; voltage = -70.0; vrest = -70.0; vth = -54.0; state = false;
			spikecount = 1;
			//spiketime = new double[100000];
			}
		LIFNeuron(const LIFNeuron & n){
			memtime = n.memtime; voltage = n.voltage; vrest = n.vrest; vth = n.vth; state = n.state;
			spikecount = n.spikecount; spiketime = n.spiketime;
			//spiketime = new double[100000];
			}
		void evolution (double t, double dt, double Iout);
		//void recordspike(double t);
		bool spiked(){return state;}
		double returnv(){return voltage;}
		int returnspike(){return spikecount;}
		double returnspiketime(){return spiketime;}
		//double returnm(){return memtime;}
		//friend double s(double t, Neuron& );
		//~Neuron(){delete[] spiketime;}
};
