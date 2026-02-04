#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char ivec[16];
size_t residue;
size_t n;

void init_vars() {
    // Allocate input buffer of 512KB to ensure loop takes ~0.01 seconds
    const size_t data_size = 512 * 1024;
    in = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    
    // Initialize ivec with non-zero values to make XOR observable
    for (int i = 0; i < 16; ++i) {
        ivec[i] = (unsigned char)(i + 1);
    }
    
    // Set residue to the minimum of data_size and 16 to prevent out-of-bounds access
    // Since loop uses `n < residue` and accesses in[n] and ivec[n], residue must not exceed 16
    residue = 16;
    
    // Ensure input array has defined content
    memset(in, 0xAA, data_size);
}