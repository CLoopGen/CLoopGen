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
        int i = 0;
        for (; i < 4; ++i, ++dl) {
            t = b[i];
            r[i] = (0 - t - c) & (18446744073709551615UL);
            if (t != 0)
                c = 1;
            if (dl + 1 >= 0)
                goto exit_loop;
        }
        b += 4;
        r += 4;
        continue;
    exit_loop:
        break;
    }
}
