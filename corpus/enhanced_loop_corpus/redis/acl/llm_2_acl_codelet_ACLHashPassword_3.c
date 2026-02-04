#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char hash[32];
extern char hex[64];
extern char *cset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (2x unroll)
    for (int j = 0; j < 32; j += 2) {
        // First iteration of unroll
        hex[j * 2] = cset[(hash[j] >> 4)];
        hex[j * 2 + 1] = cset[(hash[j] & 15)];
        // Second iteration of unroll
        if (j + 1 < 32) {
            hex[(j + 1) * 2] = cset[(hash[j + 1] >> 4)];
            hex[(j + 1) * 2 + 1] = cset[(hash[j + 1] & 15)];
        }
    }
}
