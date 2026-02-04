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
    double temp[3];
    for (i = 0; i < 3; i++) {
        temp[i] = X[i] + Z[i];
        m[0][i] = X[i];
        m[1][i] = temp[i] - Z[i]; // introduces WAR dependency via temp, and intra-loop dependency
        m[2][i] = Z[i];
    }
}
