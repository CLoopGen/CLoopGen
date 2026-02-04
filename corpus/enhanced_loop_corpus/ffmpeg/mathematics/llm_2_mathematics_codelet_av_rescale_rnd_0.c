#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t c;
extern uint64_t a0;
extern uint64_t a1;
extern uint64_t t1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern
    // Simulate array-like access with stride of 2 on bit positions (access every other bit)
    uint64_t temp_a0 = a0;
    for (i = 63; i >= 0; i -= 2) {  // Strided access: step by 2
        a1 += a1 + ((temp_a0 >> i) & 1);
        t1 += t1;
        if (c <= a1) {
            a1 -= c;
            t1++;
        }
        // Handle potential underflow or ensure loop termination
        if (i == 1) break;
    }
    // Process remaining bits if any (odd indices)
    for (i = 62; i >= 0; i -= 2) {
        a1 += a1 + ((temp_a0 >> i) & 1);
        t1 += t1;
        if (c <= a1) {
            a1 -= c;
            t1++;
        }
        if (i == 0) break;
    }
}
