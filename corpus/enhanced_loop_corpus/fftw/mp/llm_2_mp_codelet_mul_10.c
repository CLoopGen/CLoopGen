#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of writing to d[2*i] and d[2*i+1], write to consecutive elements d[i] and d[i+10]
    for (i = 0; i < 10; ++i) {
        d[i] = 0;
        d[i + 10] = 0;
    }
}
