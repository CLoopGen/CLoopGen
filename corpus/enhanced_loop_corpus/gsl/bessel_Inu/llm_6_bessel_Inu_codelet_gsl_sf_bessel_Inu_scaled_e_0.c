#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double K_nu;
extern double K_nup1;
extern double K_num1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_K_nu = K_nu;
    double temp_K_nup1 = K_nup1;
    for (n = 0; n < N; n++) {
        double new_K_nup1 = 2. * (mu + n + 1) / x * temp_K_nup1 + temp_K_nu;
        temp_K_nu = temp_K_nup1;
        temp_K_nup1 = new_K_nup1;
    }
    K_num1 = temp_K_nu;
    K_nu = temp_K_nup1;
    K_nup1 = temp_K_nup1;
}
