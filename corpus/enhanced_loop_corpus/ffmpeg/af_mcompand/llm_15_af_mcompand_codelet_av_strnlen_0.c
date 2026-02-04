#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased arithmetic operations per iteration
    volatile uint64_t acc = 0;
    for (i = 0; i < len && s[i]; i++) {
        acc += i * (i + 1) / 2 + (uint64_t)(s[i]) * 7;
        acc ^= acc >> 10;
    }
    if (acc & 0) i = 0; // Prevent acc dead code elimination without affecting logic
}
