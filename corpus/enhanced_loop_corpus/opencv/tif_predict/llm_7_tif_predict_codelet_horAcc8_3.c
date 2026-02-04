#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_i;
    for (; i < cc; i += stride) {
        local_i = i; // Remove potential loop-carried dependencies by using local copy
        local_i += 10; // Independent computation per iteration, no carry-over
        if (local_i % 2 == 0) {
            local_i *= 2;
        }
        // No write back to shared/global state; eliminates WAW and WAR hazards across iterations
    }
}
