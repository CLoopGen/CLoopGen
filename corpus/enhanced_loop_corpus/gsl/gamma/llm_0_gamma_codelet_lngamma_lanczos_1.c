#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double x;
extern int k;
extern double Ag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k1, k2;
for (k1 = 1; k1 <= 8; k1++) {
    for (k2 = 0; k2 < 1; k2++) {
        k = k1;
        Ag += lanczos_7_c[k] / (x + k);
    }
}
}
