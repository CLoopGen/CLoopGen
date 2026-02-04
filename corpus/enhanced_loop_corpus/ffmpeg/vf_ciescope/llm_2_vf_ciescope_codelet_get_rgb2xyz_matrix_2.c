#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double m[3][3];
extern double S[3];
extern double X[4];
extern double Z[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern using pointer arithmetic with stride
    double (*mp)[3] = m;
    double *Xp = X;
    double *Zp = Z;
    double *Sp = S;
    for (i = 0; i < 3; i++) {
        Sp[i] = mp[i][0] * Xp[3] + mp[i][1] * 1 + mp[i][2] * Zp[3];
    }
}
