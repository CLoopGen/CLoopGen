#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nb_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_pixel / 4; i++) {
        // Variant 2: Consecutive memory access pattern with local accumulation
        // Process 4 consecutive pixels per iteration to increase locality
        int base_index = i * 4;
        // Example operations on consecutive elements (e.g., pixel data)
        // This reflects a coalesced access pattern beneficial for cache utilization
        // data[base_index]     += 1;
        // data[base_index + 1] += 1;
        // data[base_index + 2] += 1;
        // data[base_index + 3] += 1;
    }
}
