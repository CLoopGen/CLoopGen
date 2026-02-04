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
for (i = 0; i < top - 1; i += 2) {
    m = f[i + 1];
    t[i] = (l >> rb) | ((m << lb) & mask);
    if (i + 1 < top - 1) {
        unsigned long m_next = f[i + 2];
        t[i + 1] = (m >> rb) | ((m_next << lb) & mask);
    }
    l = (i + 1 < top - 1) ? f[i + 2] : m;
}
}
