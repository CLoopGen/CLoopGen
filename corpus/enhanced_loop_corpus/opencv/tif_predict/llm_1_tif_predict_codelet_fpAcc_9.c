#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (count > 8) {
        int outer_count = count;
        for (int step = 0; step < outer_count; step += 8) {
            for (int unroll = 0; unroll < 8 && (count - step) > 0; ++unroll) {
                count--; // Simulate partial decrement per unrolled iteration
            }
            if (count <= 8) break;
        }
    }
}
