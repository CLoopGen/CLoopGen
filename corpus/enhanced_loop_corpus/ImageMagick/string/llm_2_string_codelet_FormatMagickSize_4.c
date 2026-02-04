#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char **units;
extern double bytes;
extern double extent;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed bound to avoid repeated pointer arithmetic
    ssize_t idx = 0;
    const char *next_unit = units[1];
    while ((extent >= bytes) && (next_unit != (const char *)((void *)0))) {
        extent /= bytes;
        idx++;
        next_unit = units[idx + 1];
    }
    i = idx;
}
