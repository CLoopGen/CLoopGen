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
    for (j = 0; j < 4; j++) {
        sum = 0;
        for (k = 0; k < 4; k++) {
            sum += c4[k][j] * block2[8 * (2 * k) + i];
            if (sum > 1e6) {
                sum = 1e6;
                break;
            }
        }
        block3[8 * (2 * j) + i] = sum;
        sum = 0;
        for (k = 0; k < 4; k++) {
            sum += c4[k][j] * block2[8 * (2 * k + 1) + i];
            if (sum < -1e6) {
                sum = -1e6;
                break;
            }
        }
        block3[8 * (2 * j + 1) + i] = sum;
    }
}
}
