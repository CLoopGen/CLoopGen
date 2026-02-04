#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *b;
extern int dl;
extern unsigned long c;
extern unsigned long t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        t = b[0];
        r[0] = (0 - t - c) & (18446744073709551615UL);
        c = (t != 0) ? 1 : c;
        if (++dl >= 0)
            break;
        t = b[1];
        r[1] = (0 - t - c) & (18446744073709551615UL);
        c = (t != 0) ? 1 : c;
        if (++dl >= 0)
            break;
        t = b[2];
        r[2] = (0 - t - c) & (18446744073709551615UL);
        c = (t != 0) ? 1 : c;
        if (++dl >= 0)
            break;
        t = b[3];
        r[3] = (0 - t - c) & (18446744073709551615UL);
        c = (t != 0) ? 1 : c;
        if (++dl >= 0)
            break;
        b += 4;
        r += 4;
    }
}
