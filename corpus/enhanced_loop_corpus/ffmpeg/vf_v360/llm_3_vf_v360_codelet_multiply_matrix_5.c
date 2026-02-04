#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float c[3][3];
extern  float a[3][3];
extern  float b[3][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Use consecutive linear indexing to improve spatial locality
    float *ap = &a[0][0];
    float *bp = &b[0][0];
    float *cp = &c[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float sum = 0.F;
            for (int k = 0; k < 3; k++) {
                // Access a[i][k] and b[k][j] using linearized indices with consecutive pattern in a, strided in b
                sum += ap[i*3 + k] * bp[k*3 + j];
            }
            cp[i*3 + j] = sum;
        }
    }
}
