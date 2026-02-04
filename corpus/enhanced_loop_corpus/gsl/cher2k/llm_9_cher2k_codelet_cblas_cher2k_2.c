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
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        int idx1 = 2 * (ldc * i + i), idx2 = 2 * (ldc * (i+1) + (i+1));
        (((float *)C)[idx1]) *= beta;
        (((float *)C)[idx1 + 1]) = 0.;
        (((float *)C)[idx2]) *= beta;
        (((float *)C)[idx2 + 1]) = 0.;
        for (j = i + 1; j < N; j++) {
            int base1 = 2 * (ldc * i + j), base2 = 2 * (ldc * (i+1) + j);
            (((float *)C)[base1]) *= beta;
            (((float *)C)[base1 + 1]) *= beta;
            (((float *)C)[base2]) *= beta;
            (((float *)C)[base2 + 1]) *= beta;
        }
    } else {
        (((float *)C)[2 * (ldc * i + i)]) *= beta;
        (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
        for (j = i + 1; j < N; j++) {
            (((float *)C)[2 * (ldc * i + j)]) *= beta;
            (((float *)C)[2 * (ldc * i + j) + 1]) *= beta;
        }
    }
}
}
