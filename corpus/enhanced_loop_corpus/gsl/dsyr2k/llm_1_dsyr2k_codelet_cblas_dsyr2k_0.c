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
for (i = 0; i < N; i++) {
    for (int k = 0; k <= i; k++) {
        for (j = i; j < N; j++) {
            if (k == i) {
                C[ldc * i + j] = 0.;
            }
        }
    }
}
}
