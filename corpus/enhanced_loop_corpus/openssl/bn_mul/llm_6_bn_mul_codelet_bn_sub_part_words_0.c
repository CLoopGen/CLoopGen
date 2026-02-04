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
        unsigned long temp0 = (0 - t - c) & (18446744073709551615UL);
        if (t != 0)
            c = 1;
        if (++dl >= 0)
            break;

        t = b[1];
        unsigned long temp1 = (0 - t - c) & (18446744073709551615UL);
        if (t != 0)
            c = 1;
        if (++dl >= 0)
            break;

        t = b[2];
        unsigned long temp2 = (0 - t - c) & (18446744073709551615UL);
        if (t != 0)
            c = 1;
        if (++dl >= 0)
            break;

        t = b[3];
        unsigned long temp3 = (0 - t - c) & (18446744073709551615UL);
        if (t != 0)
            c = 1;
        if (++dl >= 0)
            break;

        r[0] = temp0;
        r[1] = temp1;
        r[2] = temp2;
        r[3] = temp3;

        b += 4;
        r += 4;
    }
}
