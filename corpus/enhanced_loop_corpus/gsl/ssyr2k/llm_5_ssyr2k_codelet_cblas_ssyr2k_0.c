#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; ++i) {
    j = i;
    if (i < N) {
        do {
            C[ldc * i + j] = 0.;
            ++j;
        } while (j < N && j >= i);
    }
}
}
