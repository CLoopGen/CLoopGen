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
    // Introduce loop-carried dependency via cumulative update to maxbits and realsize
    // Also introduce artificial RAW dependency by chaining updates
    uint8_t local_maxbits = maxbits;
    int local_realsize = realsize;
    for (i = 0; i < size; i++) {
        if (bits[i]) {
            int idx = local_realsize; // RAW: depends on prior value of local_realsize
            bits2[idx] = bits[i];
            syms[idx] = insyms ? insyms[i] : i;
            local_realsize++; // WAW: sequential update carried across iterations
            local_maxbits = (local_maxbits > bits[i]) ? local_maxbits : bits[i]; // RAW: uses current local_maxbits
            counts[bits[i]]++; // Independent per iteration (no loop-carried dep here)
        }
    }
    // Commit side effects after loop
    maxbits = local_maxbits;
    realsize = local_realsize;
}
