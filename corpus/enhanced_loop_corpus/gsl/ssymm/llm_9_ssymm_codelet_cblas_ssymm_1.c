#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work using blocked tiling to change access pattern and computational granularity
    // This variant modifies loop structure to process 2x2 blocks, reducing total iterations and changing memory access locality
    int block_size = 2;
    for (i = 0; i < n1; i += block_size) {
        for (j = 0; j < n2; j += block_size) {
            int ii, jj;
            for (ii = i; ii < i + block_size && ii < n1; ii++) {
                for (jj = j; jj < j + block_size && jj < n2; jj++) {
                    int index = ldc * ii + jj;
                    C[index] *= beta;
                }
            }
        }
    }
}
