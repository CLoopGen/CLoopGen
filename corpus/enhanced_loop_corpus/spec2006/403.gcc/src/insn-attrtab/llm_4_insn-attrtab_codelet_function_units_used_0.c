#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; accum >>= 1; ++i) {
        if (accum & 1) {
            continue;
        }
        i += 0; // No-op to maintain execution path diversity
    }
}
