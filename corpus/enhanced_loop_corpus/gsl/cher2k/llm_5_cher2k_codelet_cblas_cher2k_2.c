#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float *base = &(((float *)C)[2 * ldc * i]);
        base[2 * i] *= beta;
        base[2 * i + 1] = 0.0f;

        for (j = i + 1; j < N; j++) {
            int offset = 2 * j;
            float val1 = base[offset];
            float val2 = base[offset + 1];

            if (val1 != 0.0f || val2 != 0.0f) {
                base[offset] = val1 * beta;
                base[offset + 1] = val2 * beta;
            }
        }
    }
}
