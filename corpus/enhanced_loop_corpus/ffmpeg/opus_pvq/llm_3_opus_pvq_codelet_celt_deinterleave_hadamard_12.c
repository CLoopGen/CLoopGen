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
    // Variant 2: Use indirect and strided access with reversed traversal for both loops
    // Introduces non-unit striding and reverse iteration to alter cache behavior
    for (i = stride - 1; i >= 0; i--)
        for (j = N0 - 1; j >= 0; j--)
            tmp[order[i] * N0 + j] = X[j * stride + i];
}
