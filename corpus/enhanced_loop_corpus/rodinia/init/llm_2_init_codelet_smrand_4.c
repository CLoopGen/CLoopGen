#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 2; i < 54; i += 2) {
        mrand_list[i] = (123413 * mrand_list[i - 2]) % 9223372036854775807L;
    }
    // Handle remaining indices if needed for completeness
    for (i = 1; i < 55; i += 2) {
        if (i > 0) {
            mrand_list[i] = (123413 * mrand_list[i - 1]) % 9223372036854775807L;
        }
    }
}
