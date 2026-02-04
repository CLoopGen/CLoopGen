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
    for (i = 0; i < 6; i++) {
        int j = i % 3;
        double temp1 = m[j][0] * X[3];
        double temp2 = m[j][1] * 1.0;
        double temp3 = m[j][2] * Z[3];
        S[j] = temp1 + temp2 + temp3;
        if (i >= 3) {
            S[j] += m[j][(i-3)+1] * X[i-3];
        }
    }
}
