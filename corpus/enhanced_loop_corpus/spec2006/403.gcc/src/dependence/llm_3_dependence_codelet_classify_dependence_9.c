#include <stdio.h>

#include <inttypes.h>

extern int *separability;
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int idx;
extern int cidx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary index array to access iiv_used and oiv_used indirectly,
    // simulating irregular or data-dependent memory access patterns.
    // Since we cannot introduce new global arrays, simulate remapping using arithmetic.
    for (int step = 0; step < count; step++) {
        // Map iteration step to virtual idx using bit-reversal-like permutation (for indirect effect)
        int vidx = 1 + ((step & 1) ? count - (step >> 1) : (step >> 1));
        if (vidx > count) continue;
        for (int s = 0; s < count; s++) {
            int vcidx = 1 + ((s & 1) ? count - (s >> 1) : (s >> 1));
            if (vcidx > count) continue;
            if (vidx != vcidx && iiv_used[vidx] && oiv_used[vcidx] && iiv_used[vidx] == oiv_used[vcidx])
                *separability = 0;
        }
    }
}
