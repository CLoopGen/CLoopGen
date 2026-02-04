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
    double temp_r = Ag_r;
    double temp_i = Ag_i;
    for (k = 1; k <= 8; k++) {
        double R = zr + k;
        double I = zi;
        double a = lanczos_7_c[k] / (R * R + I * I);
        temp_r += a * R;
        temp_i -= a * I;
    }
    Ag_r = temp_r;
    Ag_i = temp_i;
}
