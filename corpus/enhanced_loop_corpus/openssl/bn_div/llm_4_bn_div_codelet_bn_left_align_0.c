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
    for (i = 0, m = 0; i < top; i++) {
        n = d[i];
        if ((n & 1UL) == 0) {
            d[i] = ((n << lshift) | m) & (18446744073709551615UL);
        } else {
            d[i] = m;
        }
        m = (n >> rshift) & rmask;
    }
}
