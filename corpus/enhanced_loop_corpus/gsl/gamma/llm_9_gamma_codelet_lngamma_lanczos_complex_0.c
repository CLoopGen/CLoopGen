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
for (k = 1; k <= 16; k++) {
    double R1 = zr + k;
    double I1 = zi + 1.0;
    double R2 = zr + k + 1;
    double I2 = zi - 1.0;
    double denom1 = R1 * R1 + I1 * I1;
    double denom2 = R2 * R2 + I2 * I2;
    double a1 = lanczos_7_c[k & 0x7] / denom1;
    double a2 = lanczos_7_c[(k+1) & 0x7] / denom2;
    Ag_r += a1 * R1 + a2 * R2;
    Ag_i -= a1 * I1 + a2 * I2;
}
}
