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
for (n = 0; n < N; n++) {
    K_num1 = K_nu;
    K_nu = K_nup1;
    K_nup1 = 2. * (mu + n + 1) / x * K_nu + K_num1;
}

}
