#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern const char *PL_hexdigit;
extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // This variant processes two elements at a time, assuming aint is even.
    // It reduces branching by handling even and odd iterations in pairs.
    I32 limit = aint - (aint % 2); // Ensure even number of iterations
    for (len = 0; len < limit; len += 2) {
        // Even index: load new byte
        bits = s[len / 2]; // Load once every two iterations
        str[0] = PL_hexdigit[(bits >> 4) & 15]; // High nibble

        // Odd index: shift and reuse bits
        bits <<= 4;
        str[1] = PL_hexdigit[(bits >> 4) & 15]; // Low nibble after shift

        str += 2; // Advance str by two positions
    }
    // Handle leftover if aint is odd
    if (aint % 2) {
        len = aint - 1;
        bits = s[len / 2];
        *str++ = PL_hexdigit[(bits >> 4) & 15];
    }
}
