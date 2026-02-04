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
for (i = 0; i < 6; i += 2) {
    int j = i % 3;
    m[0][j] = S[j] * X[j];
    m[1][j] = S[j];
    m[2][j] = S[j] * Z[j];
}
}
