#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned int lb;
extern unsigned int rb;
extern unsigned long *t;
extern unsigned long *f;
extern unsigned long l;
extern unsigned long m;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (top > 1) {
    for (i = 0; i < top - 1; i++) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            m = f[i + 1];
            t[i] = (l >> rb) | ((m << lb) & mask);
            l = m;
        }
    }
}
}
