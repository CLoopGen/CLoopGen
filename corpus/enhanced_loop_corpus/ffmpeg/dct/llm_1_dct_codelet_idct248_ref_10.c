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
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                if (k == 0)
                    sum = 0;
                sum += c8[k][j] * block1[8 * i + k];
                if (k == 7)
                    block2[8 * i + j] = sum;
            }
        }
    }
}
