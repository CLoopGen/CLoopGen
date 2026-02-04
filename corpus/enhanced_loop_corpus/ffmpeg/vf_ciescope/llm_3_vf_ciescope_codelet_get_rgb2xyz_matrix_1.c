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
    // Variant 2: Consecutive memory layout simulation using pointer arithmetic
    double *m_ptr = &m[0][0];  // Flatten matrix base pointer
    for (i = 0; i < 3; i++) {
        *(m_ptr + 0*3 + i) = X[i];      // m[0][i]
        *(m_ptr + 1*3 + i) = 1;         // m[1][i]
        *(m_ptr + 2*3 + i) = Z[i];      // m[2][i]
    }
}
