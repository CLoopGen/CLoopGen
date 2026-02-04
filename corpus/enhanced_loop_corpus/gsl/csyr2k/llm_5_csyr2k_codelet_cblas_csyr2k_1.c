#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        float *base = (float *)C;
        int offset = 2 * (ldc * i + j);
        if (i % 2 == 0) {
            base[offset] = 0.;
        } else {
            base[offset] = 0.;
            base[offset + 1] = 0.;
        }
    }
}
}
