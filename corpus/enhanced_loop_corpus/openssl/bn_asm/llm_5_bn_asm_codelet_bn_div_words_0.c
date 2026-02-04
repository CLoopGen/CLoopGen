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
    if ((h >> 32) != dh)
        q = h / dh;
    else
        q = 4294967295L;
    th = q * dh;
    tl = dl * q;
    for (;;) {
        t = h - th;
        unsigned long high_masked = (t << 32) | ((l & 18446744069414584320UL) >> 32);
        if ((t & 18446744069414584320UL))
            goto exit_inner;
        if (tl <= high_masked)
            goto exit_inner;
        q--;
        th -= dh;
        tl -= dl;
    }
exit_inner:
    t = tl >> 32;
    tl = (tl << 32) & 18446744069414584320UL;
    th += t;
    th += (l < tl);
    l -= tl;
    h -= th;
    if (h + d < th) {
        h += d;
        q--;
    }
    if (--count == 0)
        break;
    ret = q << 32;
    h = ((h << 32) | (l >> 32)) & 18446744073709551615UL;
    l = (l & 4294967295L) << 32;
}
}
