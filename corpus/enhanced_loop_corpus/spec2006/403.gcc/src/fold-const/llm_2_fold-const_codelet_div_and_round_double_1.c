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
    // Variant 1: Strided memory access with stride of 2 (wrapped indexing to stay in bounds)
    int stride = 2;
    for (i = (4 - 1) * stride; i >= 0; i -= stride) {
        int idx = i % 4;  // Wrap index to stay within [0,3]
        work = num[idx] + carry * ((unsigned long)1 << (8 * 8) / 2);
        quo[idx] = work / lden;
        carry = work % lden;
    }
}
