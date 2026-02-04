#include <stdio.h>

#include <inttypes.h>

extern unsigned long h;
extern unsigned long l;
extern unsigned long d;
extern unsigned long dh;
extern unsigned long dl;
extern unsigned long q;
extern unsigned long ret;
extern unsigned long th;
extern unsigned long tl;
extern unsigned long t;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    unsigned long predicted_q = 4294967295L;
    unsigned long condition = (h >> 32) == dh;
    q = condition ? predicted_q : h / dh;
    th = q * dh;
    tl = q * dl;
    // Eliminate loop-carried dependency on q from previous iteration by isolating computation
    // Introduce artificial data dependency using conditional flags via arithmetic
    for (;;) {
        t = h - th;
        unsigned long high_bits_set = !!(t & 18446744069414584320UL);
        unsigned long compare_val = (t << 32) | ((l & 18446744069414584320UL) >> 32);
        if (high_bits_set || tl <= compare_val)
            break;
        q = q - 1;
        th = th - dh;
        tl = tl - dl;
    }
    t = tl >> 32;
    tl = (tl << 32) & 18446744069414584320UL;
    th = th + t;
    th = l < tl ? th + 1 : th; // Replace conditional branch with arithmetic-like behavior (data flow change)
    l = l - tl;
    h = h < th ? h + d - th : h - th; // Combine two dependent operations to reduce intermediate state dependencies
    if (--count == 0)
        break;
    ret = q << 32;
    // Modify update order to eliminate temporary overlap; enforce strict sequentiality
    unsigned long new_l = (l & 4294967295L) << 32;
    unsigned long new_h = ((h << 32) | (l >> 32)) & 18446744073709551615UL;
    l = new_l;
    h = new_h; // Update h only at end to break early reuse (modify loop-carried dep)
}
}
