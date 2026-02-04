#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reduced frequency
    // Instead of processing every byte in descending order, we process every 2nd byte first, then fill in
    // Simulates a strided access pattern; assumes bytes is even for simplicity
    gcov_type temp_value = 0;
    int step = 2;
    int phase, j;

    // Two phases: first odd indices (in original descending order), then even
    for (phase = 1; phase >= 0; phase--) {
        for (j = i; j >= 0; j--) {
            if (j % 2 != phase) continue;
            temp_value = temp_value * 256 + (source[j] & ((size_t)j == (bytes - 1) ? 127 : 255));
        }
    }
    value = temp_value;
}
