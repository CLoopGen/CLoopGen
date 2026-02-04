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
double temp[4][2];
for (j = 0; j < 4; j++) {
    for (i = 0; i < 8; i++) {
        for (int t = 0; t < 2; t++) {
            temp[j][t] = 0;
            for (k = 0; k < 4; k++) {
                temp[j][t] += c4[k][j] * block2[8 * (2 * k + t) + i];
            }
            block3[8 * (2 * j + t) + i] = temp[j][t];
        }
    }
}
}
