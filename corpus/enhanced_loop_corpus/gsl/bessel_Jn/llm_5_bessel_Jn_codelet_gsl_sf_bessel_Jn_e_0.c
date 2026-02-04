#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double x;
extern double Jkp1;
extern double Jk;
extern double Jkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = n; k > 0; k--) {
    Jkm1 = 2. * k / x * Jk - Jkp1;
    if (k % 2 == 1) {
        Jkp1 = Jk;
        Jk = Jkm1;
    } else {
        Jk = Jkp1;
        Jkp1 = Jkm1;
    }
}
}
