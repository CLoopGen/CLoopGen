#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t bits_per_pixel;
extern size_t one;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    unsigned char *base = q;
    for (; i < (ssize_t)(one << bits_per_pixel); i++) {
        size_t offset = i * 3;
        base[offset + 0] = (unsigned char)0;
        base[offset + 1] = (unsigned char)0;
        base[offset + 2] = (unsigned char)0;
    }
    q = base + 3 * ((one << bits_per_pixel) - (one - i)); // Update q to reflect advancement
}
