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
for (i = 0, m = 0; i < top; i += 2) {
    if (i + 1 < top) {
        n = d[i];
        unsigned long n2 = d[i + 1];
        d[i] = ((n << lshift) | m) & (18446744073709551615UL);
        m = (n >> rshift) & rmask;
        d[i + 1] = ((n2 << lshift) | m) & (18446744073709551615UL);
        m = (n2 >> rshift) & rmask;
    } else {
        n = d[i];
        d[i] = ((n << lshift) | m) & (18446744073709551615UL);
        m = (n >> rshift) & rmask;
    }
}
}
