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
    // Variant 2: Consecutive array-like access via flattened indexing to promote spatial locality
    double *m_flat = &m[0][0];  // Flatten 3x3 matrix into linear array
    double *Sp = S;
    for (i = 0; i < 3; i++) {
        Sp[i] = m_flat[i*3 + 0] * X[3] + m_flat[i*3 + 1] * 1 + m_flat[i*3 + 2] * Z[3];
    }
}
