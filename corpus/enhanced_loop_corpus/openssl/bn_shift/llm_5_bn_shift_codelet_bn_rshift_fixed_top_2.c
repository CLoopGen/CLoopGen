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
for (i = 0; i < top - 1 && lb > 0; i++) {
    m = f[i + 1];
    if (rb >= 64) {
        t[i] = m << lb;
    } else {
        t[i] = (l >> rb) | ((m << lb) & mask);
    }
    l = m;
}
}
