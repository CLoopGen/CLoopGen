#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c4[4][4];
extern double block2[64];
extern double block3[64];
extern double sum;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder computations to access block2 and block3 in a more consecutive manner by swapping inner loop order
    // and restructuring indexing to improve spatial locality.

    for (i = 0; i < 8; i++) {
        for (k = 0; k < 4; k++) {
            double c4k[4];
            for (j = 0; j < 4; j++) {
                c4k[j] = c4[k][j];
            }
            int idx1 = 8 * (2 * k) + i;
            int idx2 = 8 * (2 * k + 1) + i;
            double temp1 = block2[idx1];
            double temp2 = block2[idx2];
            for (j = 0; j < 4; j++) {
                block3[8 * (2 * j) + i] += c4k[j] * temp1;
                block3[8 * (2 * j + 1) + i] += c4k[j] * temp2;
            }
        }
    }
}
