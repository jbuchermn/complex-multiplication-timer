#include <iostream>
#include <complex>
#include <ctime>

#include <Eigen/Dense>

void matmul(int dim, const std::complex<double>* mat, const std::complex<double>* vec, std::complex<double>* res){
    for(int j=0; j<dim; j++){
        for(int i=0; i<dim; i++){
            res[i]+=mat[j*dim+i]*vec[j];
        }
    }
}


void matmul_Eigen(int dim, const std::complex<double>* mat, const std::complex<double>* vec, std::complex<double>* res){
    Eigen::Map<Eigen::VectorXcd>(res, dim)+=Eigen::Map<Eigen::MatrixXcd>(const_cast<std::complex<double>*>(mat), dim, dim)*Eigen::Map<Eigen::VectorXcd>(const_cast<std::complex<double>*>(vec), dim);
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


    clock_t t;
    double ns;

    printf("Appc:     %9d\n",dim*dim);
    
    t = clock();
    for(int k=0; k<runs; k++) matmul(dim, mat, vec, res);
    t = clock() - t;
    ns=1.e9*t/CLOCKS_PER_SEC;
    
    printf("------Simple--------\n");
    printf("Time:     %12.2fns\n", ns/runs);
    printf("Time/op:  %12.2fns\n", ns/(runs*dim*dim));

    for(int i=0; i<dim;     i++) res[i]=0;
    t = clock();
    for(int k=0; k<runs; k++) matmul_Eigen(dim, mat, vec, res);
    t = clock() - t;
    ns=1.e9*t/CLOCKS_PER_SEC;

    printf("------Eigen--------\n");
    printf("Time:     %12.2fns\n", ns/runs);
    printf("Time/op:  %12.2fns\n", ns/(runs*dim*dim));

    return 0;
}
