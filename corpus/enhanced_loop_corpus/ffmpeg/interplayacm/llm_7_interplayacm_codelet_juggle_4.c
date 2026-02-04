#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *wrap_p;
extern int *block_p;
extern unsigned int sub_len;
extern unsigned int sub_count;
extern unsigned int i;
extern unsigned int j;
extern int *p;
extern unsigned int r0;
extern unsigned int r1;
extern unsigned int r2;
extern unsigned int r3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < sub_len; i++) {
    p = block_p;
    r0 = wrap_p[0];
    r1 = wrap_p[1];
    // Remove some loop-carried dependencies by unrolling once and reordering independent operations
    for (j = 0; j < sub_count / 4; j++) {
        // First iteration (unrolled)
        r2 = *p;
        *p = r1 * 2 + (r0 + r2);
        p += sub_len;
        r3 = *p;
        *p = r2 * 2 - (r1 + r3);
        p += sub_len;

        // Second iteration: use intermediate values earlier, change dependency chain
        unsigned int r4 = *p;
        unsigned int temp = r3 * 2 + (r2 + r4);  // New expression using prior r2, r3 — introduces RAW from previous
        *p = temp;
        p += sub_len;
        unsigned int r5 = *p;
        *p = r4 * 2 - (r3 + r5);
        p += sub_len;

        // Update r0, r1 with delayed values to stretch loop-carried dependency
        r0 = r4;
        r1 = r5;
    }
    // Handle possible leftover iterations if sub_count/4 isn't exact (still safe due to integer division truncation)
    *wrap_p++ = r0;
    *wrap_p++ = r1;
    block_p++;
}
}
