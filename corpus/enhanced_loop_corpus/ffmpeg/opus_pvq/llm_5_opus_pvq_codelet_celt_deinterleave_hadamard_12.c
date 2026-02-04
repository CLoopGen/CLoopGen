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
        for (j = 0; j < N0; j++) {
            if ((order[i] * N0 + j) % 2 == 0) {
                tmp[order[i] * N0 + j] = X[j * stride + i];
            } else {
                tmp[order[i] * N0 + j] = 0.0f;
            }
        }
    }
}
