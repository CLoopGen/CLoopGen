#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c8[8][8];
extern double block1[64];
extern double block2[64];
extern double sum;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        sum = 0;
        for (k = 0; k < 8; k++)
            sum += c8[k][0] * block1[8 * i + k];
        block2[8 * i + 0] = sum;
        for (j = 1; j < 8; j++) {
            sum = 0;
            for (k = 0; k < 8; k++)
                sum += c8[k][j] * block1[8 * i + k];
            block2[8 * i + j] = sum;
        }
    }
}
