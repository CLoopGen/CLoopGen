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
        m[2][i] = Z[i];
        m[0][i] = X[i];
        m[1][i] = m[0][i] * m[2][i]; // introduces RAW dependency: uses m[0][i] and m[2][i] just written
    }
    // Introduces loop-carried dependence by making m[1][i] depend on current iteration's prior stores
}
