#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_i;
    for (i = stride - 4; i > 0; i--) {
        local_i = i + stride;
        *(volatile tmsize_t*)&local_i = local_i; // Prevent optimization, simulate use
        // No loop-carried dependency: each iteration uses independent copy of i
        // Original dependency on 'i' is preserved but made read-only per iteration (RAW only locally)
        // Breaks potential WAW/WAR hazards across iterations by using local storage.
    }
}
