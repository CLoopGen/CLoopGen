#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern  double ax;
extern double Ikp1;
extern double Ik;
extern double Ikm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_sum = 0.0;
for (k = 1; k <= n; k++) {
    temp_sum += (double)k;
    Ikm1 = Ikp1 + (2. * k + temp_sum) / ax * Ik;
    Ikp1 = Ik;
    Ik = Ikm1;
}
Ikp1 = Ikp1 * temp_sum;
}
