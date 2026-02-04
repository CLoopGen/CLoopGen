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
    unsigned long prev_m = 0;
    unsigned long next_m;
    for (i = 0; i < top; i++) {
        n = d[i];
        d[i] = ((n << lshift) | prev_m) & (18446744073709551615UL);
        next_m = (n >> rshift) & rmask;
        prev_m = next_m;
    }
    m = prev_m;
}
