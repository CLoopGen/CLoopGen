#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        double temp = 0.0;
        for (int k = 0; k < 4; k++) {
            C[ldc * i + j] += temp + k;
        }
        if (i + 1 < N) {
            C[ldc * (i + 1) + j] = 0.0;
        }
    }
}
}
