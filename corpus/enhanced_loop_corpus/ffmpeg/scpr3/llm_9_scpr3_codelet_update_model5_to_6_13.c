#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 8192; e++) {
        d <<= 1;
        d += d >> 2; // Additional arithmetic to increase per-iteration workload
    }
}
