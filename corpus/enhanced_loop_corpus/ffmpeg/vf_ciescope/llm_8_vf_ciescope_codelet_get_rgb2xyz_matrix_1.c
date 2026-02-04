#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double m[3][3];
extern double X[4];
extern double Z[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        m[0][i] = X[i] + Z[i] - 1.0;
        m[1][i] = (X[i] * Z[i]) + 2.0;
        m[2][i] = X[i] * Z[i] * X[i];
    }
}
