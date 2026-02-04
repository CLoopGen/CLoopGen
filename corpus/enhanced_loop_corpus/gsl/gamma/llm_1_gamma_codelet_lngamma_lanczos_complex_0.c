#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double zr;
extern double zi;
extern int k;
extern double Ag_r;
extern double Ag_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth = 0; depth < 1; depth++) {
    for (k = 1; k <= 8; k++) {
        double R = zr + k;
        double I = zi;
        double a = lanczos_7_c[k] / (R * R + I * I);
        Ag_r += a * R;
        Ag_i -= a * I;
    }
}
}
