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
        for (k = 0; k < 8; k += 2) {
            sum += c4[k/2][j] * block2[8 * k + i];
        }
        block3[8 * (2 * j) + i] = sum;
        sum = 0;
        for (k = 1; k < 8; k += 2) {
            sum += c4[k/2][j] * block2[8 * k + i];
        }
        block3[8 * (2 * j + 1) + i] = sum;
    }
}
}
