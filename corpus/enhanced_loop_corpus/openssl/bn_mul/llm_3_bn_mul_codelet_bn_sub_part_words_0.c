#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *b;
extern int dl;
extern unsigned long c;
extern unsigned long t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2 (process even indices in pairs)
    int stride = 2;
    int count = 0;
    for (;;) {
        int i0 = count * stride;
        t = b[i0];
        r[i0] = (0 - t - c) & 18446744073709551615UL;
        if (t != 0)
            c = 1;
        if (++dl >= 0) break;

        int i1 = i0 + 1;
        t = b[i1];
        r[i1] = (0 - t - c) & 18446744073709551615UL;
        if (t != 0)
            c = 1;
        if (++dl >= 0) break;

        count++;
        if (count >= 2) { // After processing two strided pairs (i.e., 4 elements total)
            b += 4;
            r += 4;
            break;
        }
        if (++dl >= 0) break;
        if (++dl >= 0) break;
    }
}
