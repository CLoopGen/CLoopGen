#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse order, with adjusted bounds)
    int start = (4 - 1) & ~1; // Round down to nearest even index
    for (i = start; i >= 0; i -= 2) {
        int idx = i; // Stride of 2: indices ..., 4, 2, 0 (but capped by original bound)
        work = (num[idx] * scale) + carry;
        num[idx] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
    }
    // Final pass on odd indices if needed, but problem states fixed 5 elements and i from 0 to 3
    // This variant processes only even indices due to strided access pattern
}
