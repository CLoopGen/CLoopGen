#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        int index = i * 256; // Flatten access: treat each row as consecutive in memory
        for (int j = 0; j < 256; j++) {
            ((real_t*)aa)[index + j] = (real_t)0.; // Consecutive write via flattened indexing
        }
        ((real_t*)aa)[index + i] = (real_t)1.; // Set diagonal using flat offset
    }
}
}
