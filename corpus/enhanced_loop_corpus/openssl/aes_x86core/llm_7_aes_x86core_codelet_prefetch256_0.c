#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_sum = 0;
    for (i = 0; i < 256 / sizeof(t[0]); i += 32 / sizeof(t[0])) {
        local_sum ^= t[i] ^ t[(i + 32 / sizeof(t[0])) % (256 / sizeof(t[0]))]; // Introduces RAW dependency with look-ahead access
    }
    sum = local_sum; // Eliminates loop-carried dependency on shared `sum`, computes locally first
}
