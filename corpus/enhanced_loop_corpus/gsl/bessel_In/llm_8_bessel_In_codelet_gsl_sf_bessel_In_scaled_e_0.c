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
int k_start = n > 100 ? n : 100;
for (k = k_start; k >= 1; k -= 2) {
    if (k < n) {
        Ikm1 = Ikp1 + 2. * (k+1) / ax * Ik;
        Ikp1 = Ik;
        Ik = Ikm1;
    }
    Ikm1 = Ikp1 + 2. * k / ax * Ik;
    Ikp1 = Ik;
    Ik = Ikm1;
}
}
