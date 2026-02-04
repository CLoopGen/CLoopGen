#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double Ynp1_prev = Ynp1;
    for (n = 1; n <= N; n++) {
        Ynp1 = 2. * (mu + n - 1) / x * Yn - Ynm1;
        Ynm1 = Yn;
        Yn = Ynp1_prev;
        Ynp1_prev = Ynp1;
    }
}
