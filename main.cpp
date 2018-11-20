#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

void equations(double* v, double* r, double* delta_m, double* rho, double* P, double* e, double dt, int n_rad){
    for(int k=0; k<=n_rad; k++){
    *(v + k) = *(v + k - n_rad) - 4*M_PI*(*(r+k))*(*(P+k+1) - *(P+k))*dt/(*(delta_m+k))
    }
    return;
}


int main()
{
    int n_temps = 10;
    int n_rad = 10;
    double dt = 0.1;

    double* r = (double*) malloc((n_temps*n_rad+1)*sizeof(double));
    double* v = (double*) malloc((n_temps*n_rad+1)*sizeof(double));
    double* e = (double*) malloc((n_temps*n_rad+1)*sizeof(double));
    double* rho = (double*) malloc((n_temps*n_rad+1)*sizeof(double));
    double* p = (double*) malloc((n_temps*n_rad+1)*sizeof(double));
    double* delta_m = (double*) malloc((n_rad+1)*sizeof(double));

    //init(r, v, e, rho, p)

    for(int k=0;k<=(n_rad-1);k++){
        *(delta_m + k) = (4*M_PI/3)*(pow((*(r+k+1)),3) - pow((*(r+k)),3))*(*(rho+k));
    }

   for(int n=1;n<=n_temps;n++){
        equations(v+n*n_rad,r+n*n_rad, delta_m, rho+n*n_rad, p+n*n_rad, e+n*n_rad, dt, n_rad);
    }

    cout << "Hello world!" << endl;
    free(r);
    free(v);
    free(e);
    free(rho);
    free(p);
    free(delta_m);
    return 0;
}
