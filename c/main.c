#include <stdio.h>
#include <complex.h>
#include <time.h>
#include <stdlib.h>

void matmul(int dim, const double complex* mat, const double complex* vec, double complex* res){
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

    double complex* mat = malloc(dim*dim*sizeof(complex double));
    double complex* vec = malloc(dim    *sizeof(complex double));
    double complex* res = malloc(dim    *sizeof(complex double));

    for(int i=0; i<dim*dim; i++) mat[i]=i+1./i*I;
    for(int i=0; i<dim;     i++) vec[i]=i;
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
