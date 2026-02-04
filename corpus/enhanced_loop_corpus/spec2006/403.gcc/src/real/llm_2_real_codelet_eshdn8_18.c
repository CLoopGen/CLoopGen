#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short newbyt;
extern unsigned short oldbyt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled-like stride of 1
    // Instead of modifying x in-place with post-increment, we use a local pointer offset
    // to access consecutive elements in a forward sequential pattern.
    unsigned short *base = x;
    int limit = i + 5; // equivalent to original loop bound: i starts at 2, runs to 8 (6+3)
    for (i = 2; i < limit; i++) {
        newbyt = base[i - 2] << 8;   // shifted access starting from base
        base[i - 2] >>= 8;
        base[i - 2] |= oldbyt;
        oldbyt = newbyt;
    }
}
