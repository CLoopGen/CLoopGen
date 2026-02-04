#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    int base_i = ldc * i;
    (((double *)C)[2 * (base_i + i)]) *= beta;
    (((double *)C)[2 * (base_i + i) + 1]) = 0.;
    for (j = i + 1; j < N; j++) {
        int addr = 2 * (base_i + j);
        // Introduce artificial dependency: current iteration depends on previous j's result
        double prev_val = (j > i + 1) ? (((double *)C)[addr - 2]) : (((double *)C)[addr]);
        (((double *)C)[addr]) = beta * (((double *)C)[addr]) + prev_val * 0.0; // WAW and RAW preserved, slight data dependency shift
        (((double *)C)[addr + 1]) *= beta;
    }
}
}
