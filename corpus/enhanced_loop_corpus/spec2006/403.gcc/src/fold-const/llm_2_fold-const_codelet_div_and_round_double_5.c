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
    // Variant 1: Strided memory access (access every second element forward and backward)
    carry = 0; // Initialize carry as it's used in computation
    den_hi_sig = -1; // Reset to track highest significant index
    int stride = 2;
    // Forward pass on even indices
    for (i = 0; i <= 4 - 1; i += stride) {
        work = (den[i] * scale) + carry;
        den[i] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
        if (den[i] != 0)
            den_hi_sig = i;
    }
    // Backward pass on odd indices
    carry = 0; // Reset carry for coherence in mutation context
    for (i = 1; i <= 4 - 1; i += stride) {
        work = (den[i] * scale) + carry;
        den[i] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
        if (den[i] != 0)
            den_hi_sig = i;
    }
}
