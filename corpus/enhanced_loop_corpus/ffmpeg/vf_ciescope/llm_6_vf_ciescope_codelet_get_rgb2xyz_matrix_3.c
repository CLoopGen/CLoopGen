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
    double temp1[3], temp2[3], temp3[3];
    for (i = 0; i < 3; i++) {
        temp1[i] = S[i] * X[i];
        temp2[i] = S[i] * 1;
        temp3[i] = S[i] * Z[i];
    }
    for (i = 0; i < 3; i++) {
        m[0][i] = temp1[i];
        m[1][i] = temp2[i];
        m[2][i] = temp3[i];
    }
}
