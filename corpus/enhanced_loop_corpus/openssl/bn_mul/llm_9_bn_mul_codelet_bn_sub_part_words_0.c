#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *b;
extern int dl;
extern unsigned long c;
extern unsigned long t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int unroll_factor = 0; unroll_factor < 2; ++unroll_factor) {
        for (int j = 0; j < 2; ++j) {
            t = b[j];
            unsigned long negated = ~t + 1; // Equivalent to -t using two's complement
            r[j] = (negated - c) & (18446744073709551615UL);
            c = (t != 0) ? 1 : c;
            if (++dl >= 0)
                goto exit_loop;
        }
        b += 2;
        r += 2;
    }
exit_loop:
    return;
}
