#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (access every element consecutively, unroll by 2 for efficiency)
    I32 i;
    for (i = 0; i < aint; i += 2) {
        // First iteration of unroll
        if (i & 7)
            bits >>= 1;
        else
            bits = *s++;
        *str++ = '0' + (bits & 1);

        // Second iteration of unroll, if within bounds
        len = i + 1;
        if (len < aint) {
            if (len & 7)
                bits >>= 1;
            else
                bits = *s++;
            *str++ = '0' + (bits & 1);
        }
    }
    len = aint; // Maintain logical state of `len`
}
