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
    if ((h >> 32) == dh)
        q = (4294967295L);
    else
        q = h / dh;
    th = q * dh;
    tl = dl * q;
    for (int i = 0; i < 3; ++i) {
        t = h - th;
        if ((t & (18446744069414584320UL)) || ((tl) <= ((t << 32) | ((l & (18446744069414584320UL)) >> 32))))
            break;
        q--;
        th -= dh;
        tl -= dl;
    }
    t = (tl >> 32);
    tl = (tl << 32) & (18446744069414584320UL);
    th += t;
    if (l < tl)
        th++;
    l -= tl;
    if (h < th) {
        h += d;
        q--;
    }
    h -= th;
    if (--count == 0)
        break;
    ret = q << 32;
    h = ((h << 32) | (l >> 32)) & (18446744073709551615UL);
    l = (l & (4294967295L)) << 32;
}
}
