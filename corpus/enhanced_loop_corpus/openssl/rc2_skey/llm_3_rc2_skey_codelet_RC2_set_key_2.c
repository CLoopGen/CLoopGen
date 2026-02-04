#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern unsigned char *k;
extern RC2_INT *ki;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with interleaved reads, unrolling by factor of 4
    // Simulates non-unit stride in input and output to increase parallelism
    int j;
    for (j = 0; j < 32; j++) {
        int src_idx1 = 127 - (j * 8 + 0);
        int src_idx2 = 127 - (j * 8 + 2);
        int src_idx3 = 127 - (j * 8 + 4);
        int src_idx4 = 127 - (j * 8 + 6);

        ki[-(j*4 + 0)] = ((k[src_idx1] << 8) | k[src_idx1 - 1]) & 65535;
        ki[-(j*4 + 1)] = ((k[src_idx2] << 8) | k[src_idx2 - 1]) & 65535;
        ki[-(j*4 + 2)] = ((k[src_idx3] << 8) | k[src_idx3 - 1]) & 65535;
        ki[-(j*4 + 3)] = ((k[src_idx4] << 8) | k[src_idx4 - 1]) & 65535;
    }
}
