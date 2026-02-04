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
    S[0] = m[0][0] * X[3] + m[0][1] * 1 + m[0][2] * Z[3];
    for (i = 1; i < 3; i++) {
        S[i] = m[i][0] * X[3] + m[i][1] * 1 + m[i][2] * Z[3] + S[i-1] * 0.0;
    }
}
