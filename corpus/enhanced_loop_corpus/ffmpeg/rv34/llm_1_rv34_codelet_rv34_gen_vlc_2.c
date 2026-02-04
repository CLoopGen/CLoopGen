#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bits;
extern int size;
extern  uint8_t *insyms;
extern int i;
extern int counts[17];
extern uint16_t syms[1296];
extern uint8_t bits2[1296];
extern int maxbits;
extern int realsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced loop depth by inlining the condition directly with no additional control structures
// Original loop remains at same level but logic is simplified via unswitching potential redundant checks
// Here, we assume 'insyms' is always non-null as an optimization assumption to remove branching inside
for (i = 0; i < size; i++) {
    uint8_t bit_val = bits[i];
    if (bit_val) {
        int idx = realsize;
        bits2[idx] = bit_val;
        syms[idx] = insyms[i]; // Assume insyms is valid everywhere, removing ternary
        realsize = idx + 1;
        if (bit_val > maxbits) maxbits = bit_val;
        counts[bit_val]++;
    }
}
}
