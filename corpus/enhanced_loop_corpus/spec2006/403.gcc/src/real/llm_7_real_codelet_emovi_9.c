#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int idx_p = 3;
    int idx_q = 0;
    for (i = 3; i < 9; i++) {
        q[idx_q] = p[idx_p]; // Replace pointer arithmetic with indexed access
        idx_p--;             // Decrement index separately — introduces anti-dependence (WAR) on idx_p
        idx_q++;             // Increment index — creates loop-carried dependence on idx_q
        // RAW dependency between loads from p and stores to q is preserved, but carried via indices
    }
}
