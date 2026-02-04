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
int k1;
for (k1 = 0; k1 < 1; k1++) {
    for (k = n; k >= 1; k--) {
        Ikm1 = Ikp1 + 2. * k / ax * Ik;
        Ikp1 = Ik;
        Ik = Ikm1;
    }
}
}
