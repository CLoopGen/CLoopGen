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



void loop() {
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // This variant processes two elements per iteration to enable consecutive array writes
    // and alternates bit shifting logic using loop index, reducing branching.

    for (len = 0; len + 1 < aint; len += 2) {
        bits = *s++;
        *str++ = PL_hexdigit[bits & 15];
        bits >>= 4;
        *str++ = PL_hexdigit[bits & 15];
    }

    // Handle leftover element if aint is odd
    if (len < aint) {
        if (len & 1)
            bits >>= 4;
        else
            bits = *s++;
        *str++ = PL_hexdigit[bits & 15];
    }
}
