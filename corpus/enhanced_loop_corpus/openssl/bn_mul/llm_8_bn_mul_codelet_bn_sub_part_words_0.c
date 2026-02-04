#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *b;
extern int dl;
extern unsigned long c;
extern unsigned long t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 8; ++i) {
        t = b[i];
        r[i] = (0 - t - c) & (18446744073709551615UL);
        if (t != 0)
            c = 1;
        if (++dl >= 0)
            break;
        if ((i + 1) % 4 == 0 && i != 7) {
            b += 4;
            r += 4;
        }
    }
}
