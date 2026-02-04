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
    for (j = i; j < N; j++) {
        float* base = (float*)C;
        int index = 2 * (ldc * i + j);
        if (i != j) {
            base[index] = 0.;
            base[index + 1] = 0.;
        } else {
            base[index] = 0.;
        }
    }
}
}
