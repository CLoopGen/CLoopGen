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
for (n = 1; n <= N; n++) {
    for (int inner = 0; inner < 1; inner++) {
        Ynp1 = 2. * (mu + n) / x * Yn - Ynm1;
        Ynm1 = Yn;
        Yn = Ynp1;
    }
}
}
