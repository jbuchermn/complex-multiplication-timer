#include <iostream>
#include <ctime>
#include <vector>
#include <complex>
#include <stdlib.h>

int main(int argc, char* argv[]){
	unsigned int n=1000000;
	srand(clock());	

	std::vector<std::complex<double> > v(100);
	for(unsigned int i=0; i<v.size(); i++) v[i]=std::complex<double>(double(rand())/RAND_MAX, double(rand())/RAND_MAX);

	clock_t t = clock();
	for(unsigned int _=0; _<n/v.size(); _++){
		for(unsigned int i=0; i<v.size(); i++) v[i]*=v[i+1%v.size()];
	}
	t = clock()-t;
	
	double nanos = double(t)/n/CLOCKS_PER_SEC*1.e9;
        std::cout<<"Result: "<<nanos<<" nanoseconds"<<std::endl;	

}
