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
    if (N <= 0) return;
    for (i = 0; i < N; i++) {
        int idx_diag = 2 * (ldc * i + i);
        (((float *)C)[idx_diag]) *= beta;
        (((float *)C)[idx_diag + 1]) = 0;

        for (j = i + 1; j < N; j++) {
            int idx = 2 * (ldc * i + j);
            (((float *)C)[idx]) *= beta;
            (((float *)C)[idx + 1]) *= beta;
        }
    }
}
