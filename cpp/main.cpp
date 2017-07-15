#include <iostream>
#include <complex>
#include <ctime>

void matmul(int dim, const std::complex<double>* mat, const std::complex<double>* vec, std::complex<double>* res){
    for(int j=0; j<dim; j++){
        for(int i=0; i<dim; i++){
            res[i]+=mat[j*dim+i]*vec[j];
        }
    }
}


int main(int argc, char* argv[]){
    int dim  = atoi(argv[1]);
    int runs = atoi(argv[2]);

    printf("MATRIX MULTIPLICATION -- dim=%d, runs=%d\n", dim, runs);

    std::complex<double>* mat = (std::complex<double>*)malloc(dim*dim*sizeof(std::complex<double>));
    std::complex<double>* vec = (std::complex<double>*)malloc(dim    *sizeof(std::complex<double>));
    std::complex<double>* res = (std::complex<double>*)malloc(dim    *sizeof(std::complex<double>));

    for(int i=0; i<dim*dim; i++) mat[i]=std::complex<double>(i,1./i);
    for(int i=0; i<dim;     i++) vec[i]=std::complex<double>(i,0.);
    for(int i=0; i<dim;     i++) res[i]=0;

    clock_t t = clock();
    for(int k=0; k<runs; k++) matmul(dim, mat, vec, res);
    t = clock() - t;
    double ns=1.e9*t/CLOCKS_PER_SEC;


    printf("Appc:     %9d\n",dim*dim);
    printf("Time:     %12.2fns\n", ns/runs);
    printf("Time/op:  %12.2fns\n", ns/(runs*dim*dim));

    return 0;
}
