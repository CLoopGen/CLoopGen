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
    for (k = 1; k <= 8; k++) {
        double R = zr + k;
        double I = zi;
        double denom = R * R + I * I;
        if (denom < 1e-12) continue;
        double a = lanczos_7_c[k] / denom;
        Ag_r += a * R;
        Ag_i -= a * I;
    }
}
