#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *tmp;
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;
extern  uint8_t *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < stride; i++) {
        if (order[i] >= 0) {
            for (j = 0; j < N0; j++) {
                tmp[j * stride + i] = X[order[i] * N0 + j];
            }
        }
    }
}
