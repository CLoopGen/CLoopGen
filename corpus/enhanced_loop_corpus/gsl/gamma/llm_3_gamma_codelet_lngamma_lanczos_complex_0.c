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
    int access_pattern[8] = {1, 3, 5, 7, 2, 4, 6, 8};
    for (k = 0; k < 8; k++) {
        int index = access_pattern[k];
        double R = zr + index;
        double I = zi;
        double a = lanczos_7_c[index] / (R * R + I * I);
        Ag_r += a * R;
        Ag_i -= a * I;
    }
}
