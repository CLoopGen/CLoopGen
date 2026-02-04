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
for (k = 1; k <= 4; k++) {
    double R = zr + 2*k;
    double I = zi;
    double denom = R * R + I * I;
    double a = lanczos_7_c[2*k] / denom;
    Ag_r += a * R;
    Ag_i -= a * I;
}
}
