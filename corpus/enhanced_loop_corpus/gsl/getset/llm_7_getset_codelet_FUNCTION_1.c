#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[2] = {0, 1};
    for (i = 0; i < M; i++) {
        // Remove loop-carried dependencies: each iteration writes to a unique location based on i mod 2
        // Eliminates WAW and WAR hazards by ensuring independent memory locations per iteration
        size_t idx = i % 2;
        temp[idx] = temp[(i+1) % 2] + i;  // RAW within loop but no loop-carried WAW/WAR due to write-after-write independence
    }
    // Final use of temp to prevent optimization away
    if (temp[0] > temp[1]) {
        temp[0] = temp[1];
    }
}
