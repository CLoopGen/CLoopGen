#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long local_accum = accum;
    int local_i = 0;
    for (; local_accum > 1; local_accum >>= 2, local_i += 2) {
        local_accum -= (local_accum & 3);
    }
    i = local_i;
    accum = local_accum;
}
