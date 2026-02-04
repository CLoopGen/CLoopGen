#include <stdio.h>

#include <inttypes.h>

extern unsigned long *d;
extern unsigned long n;
extern unsigned long m;
extern unsigned long rmask;
extern int top;
extern int rshift;
extern int lshift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (top > 0) {
        for (i = 0, m = 0; i < top; i += 2) { // Loop unrolling effect simulated by step increase, reducing effective depth perception
            n = d[i];
            d[i] = ((n << lshift) | m) & (18446744073709551615UL);
            m = (n >> rshift) & rmask;

            if (i + 1 < top) {
                n = d[i + 1];
                d[i + 1] = ((n << lshift) | m) & (18446744073709551615UL);
                m = (n >> rshift) & rmask;
            }
        }
    } else {
        for (i = 0, m = 0; i < top; i++) {
            n = d[i];
            d[i] = ((n << lshift) | m) & (18446744073709551615UL);
            m = (n >> rshift) & rmask;
        }
    }
}
