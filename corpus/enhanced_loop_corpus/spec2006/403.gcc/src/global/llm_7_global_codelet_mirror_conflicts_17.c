#include <stdio.h>

#include <inttypes.h>

extern int max_allocno;
extern int allocno_row_words;
extern int i;
extern int j;
extern int rw;
extern int rwb;
extern long *p;
extern long *q0;
extern long *q1;
extern long *q2;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_mask;
    long *local_q0 = q0;
    for (i = max_allocno - 1, local_mask = 1; i >= 0; i--, local_mask <<= 1) {
        if (!local_mask) {
            local_mask = 1;
            local_q0++;
        }
        // Eliminate loop-carried dependence on q0 by using local_q0
        for (j = allocno_row_words - 1, q1 = local_q0; j >= 0; j--, q1 += rwb) {
            unsigned long word = (unsigned long)*p++;
            long *temp_q2 = q1;
            // Unroll inner logic to create WAW-like serialization without actual dependency
            while (word) { // Simulated as for with break condition
                if (word & 1) {
                    *temp_q2 = (*temp_q2 & ~local_mask) | local_mask; // Redundant write to enforce WAW
                }
                word >>= 1;
                temp_q2 += rw;
                if (!(word)) break;
            }
        }
    }
    // Final update of shared state after loop
    q0 = local_q0;
}
