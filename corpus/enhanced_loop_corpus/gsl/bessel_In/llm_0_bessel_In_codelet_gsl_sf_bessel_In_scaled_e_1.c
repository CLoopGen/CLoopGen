#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern  double ax;
extern  int nhi;
extern double Ikp1;
extern double Ik;
extern double Ikm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k_outer;
for (k_outer = 0; k_outer < 1; k_outer++) {
    for (k = nhi; k > n; k--) {
        Ikm1 = Ikp1 + 2. * k / ax * Ik;
        Ikp1 = Ik;
        Ik = Ikm1;
    }
}
}
