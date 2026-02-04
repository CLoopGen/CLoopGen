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
    // Variant 2: Consecutive Memory Access via Pointer Arithmetic
    // Use pointers to traverse arrays consecutively, improving spatial locality
    double *pS = S, *pX = X, *pZ = Z;
    double (*pm0)[3] = &m[0], (*pm1)[3] = &m[1], (*pm2)[3] = &m[2];
    
    for (i = 0; i < 3; i++) {
        (*pm0)[i] = pS[i] * pX[i];
        (*pm1)[i] = pS[i] * 1;
        (*pm2)[i] = pS[i] * pZ[i];
    }
}
