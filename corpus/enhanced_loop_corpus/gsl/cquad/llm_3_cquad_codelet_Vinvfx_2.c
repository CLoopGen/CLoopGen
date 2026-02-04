#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V3inv[289];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and strided accumulation
    // This variant accesses V3inv with a fixed stride pattern and uses reverse iteration
    for (i = 16; i >= 0; i--) {
        c[i] = 0.0;
        for (j = 16; j >= 0; j--) {
            // Accessing fx with increasing stride via j*2, but traversing backwards
            // Simulates irregular temporal access pattern on fx while maintaining correctness
            c[i] += V3inv[i * 17 + j] * fx[j * 2];
        }
    }
}
