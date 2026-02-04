#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern long quo[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long lden;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count via unrolling semantics and simplified operations
    for (i = 8 - 1; i >= 0; i--) {
        int idx = i / 2;  // Map expanded index back to original array bounds
        unsigned long scaled_carry = (i % 2 == 0) ? carry : carry >> (8 * 4);
        work = (idx >= 0 ? num[idx] : 0) + scaled_carry;
        quo[idx] = work / lden;
        carry = work % lden;
    }
}
