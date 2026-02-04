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
for (i = 0; i < 8; i++) {
    for (k = 0; k < 4; k++) {
        for (j = 0; j < 4; j++) {
            double temp1 = c4[k][j] * block2[8 * (2 * k) + i];
            double temp2 = c4[k][j] * block2[8 * (2 * k + 1) + i];
            // Accumulate into block3 using atomic-like updates (simulated via direct indexing)
            if (k == 0) {
                block3[8 * (2 * j) + i] = 0;
                block3[8 * (2 * j + 1) + i] = 0;
            }
            block3[8 * (2 * j) + i] += temp1;
            block3[8 * (2 * j + 1) + i] += temp2;
        }
    }
}
}
