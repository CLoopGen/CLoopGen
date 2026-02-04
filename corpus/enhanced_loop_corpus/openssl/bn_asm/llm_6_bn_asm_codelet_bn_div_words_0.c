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
    unsigned long temp_q = (h >> 32) == dh ? 4294967295L : h / dh;
    th = temp_q * dh;
    tl = dl * temp_q;
    q = temp_q; // Introduce WAW dependency: q written after temp_q used
    for (;;) {
        t = h - th;
        if ((t & 18446744069414584320UL) || (tl <= ((t << 32) | ((l & 18446744069414584320UL) >> 32))))
            break;
        q--;
        th -= dh;
        tl -= dl;
    }
    t = tl >> 32;
    tl = (tl << 32) & 18446744069414584320UL;
    th += t;
    if (l < tl)
        th++;
    l -= tl;
    if (h < th) {
        h += d;
        q--; // RAW on h and th, WAR on q due to prior use in inner loop
    }
    h -= th;
    if (--count == 0)
        break;
    ret = q << 32;
    unsigned long next_h = ((h << 32) | (l >> 32)) & 18446744073709551615UL;
    unsigned long next_l = (l & 4294967295L) << 32;
    h = next_h; // Delayed write to h to modify loop-carried dependency pattern
    l = next_l;
}
}
