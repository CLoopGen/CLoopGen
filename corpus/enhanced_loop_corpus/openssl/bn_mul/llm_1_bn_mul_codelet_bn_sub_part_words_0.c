#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *b;
extern int dl;
extern unsigned long c;
extern unsigned long t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2 && dl < 0; ++outer) {
        for (int inner = 0; inner < 4 && dl < 0; ++inner) {
            t = b[inner];
            r[inner] = (0 - t - c) & (18446744073709551615UL);
            if (t != 0)
                c = 1;
            if (++dl >= 0)
                break;
        }
        if (dl >= 0) break;
        b += 4;
        r += 4;
    }
}
