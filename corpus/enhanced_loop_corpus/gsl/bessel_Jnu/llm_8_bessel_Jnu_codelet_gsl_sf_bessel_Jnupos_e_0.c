#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < N; n += 2) {
        if (n + 1 < N) {
            double Ynp2;
            Ynp1 = 2. * (mu + n) / x * Yn - Ynm1;
            Ynp2 = 2. * (mu + n + 1) / x * Ynp1 - Yn;
            Ynm1 = Ynp1;
            Yn = Ynp2;
        } else {
            Ynp1 = 2. * (mu + n) / x * Yn - Ynm1;
            Ynm1 = Yn;
            Yn = Ynp1;
        }
    }
}
