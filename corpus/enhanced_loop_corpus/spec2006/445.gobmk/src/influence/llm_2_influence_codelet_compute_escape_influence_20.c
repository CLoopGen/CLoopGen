#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, but within bounds using modulo)
    for (int i = 0; i < 4; i += 2) {
        int idx = i % 2;
        active_caches[idx] = 0;
    }
}
