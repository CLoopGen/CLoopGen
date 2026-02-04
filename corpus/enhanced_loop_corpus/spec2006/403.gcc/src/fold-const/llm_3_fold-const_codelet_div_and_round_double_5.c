#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern int den_hi_sig;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array
    int indices[4] = {3, 1, 0, 2}; // Custom access order: reorder traversal
    carry = 0;
    den_hi_sig = -1;
    for (i = 0; i <= 4 - 1; i++) {
        int idx = indices[i]; // Indirect access via lookup table
        work = (den[idx] * scale) + carry;
        den[idx] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
        if (den[idx] != 0)
            den_hi_sig = idx;
    }
}
