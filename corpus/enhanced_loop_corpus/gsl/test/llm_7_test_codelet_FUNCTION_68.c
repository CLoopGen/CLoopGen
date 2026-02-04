#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t buffer[2] = {0};
    for (i = 0; i < 1027; i++) {
        buffer[i % 2] = i + buffer[(i - 1) % 2];
    }
    // Creates loop-carried RAW dependency: current iteration reads from
    // buffer[(i-1)%2], written in prior iteration. Also introduces WAR/WAW
    // by reusing same array locations with alternating indices.
}
