#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern  unsigned char *input;
extern long length;
extern int out_count;
extern DES_LONG z0;
extern DES_LONG z1;
extern DES_LONG t0;
extern DES_LONG t1;
extern int i;
extern long l;
extern  unsigned char *cp;
extern DES_LONG *lp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; ((i < 4) && (i < out_count)); i++) {
    cp = input;
    l = length;
    for (; l > 0; ) {
        t0 = (DES_LONG)(*(cp++));
        if (l > 1) {
            t0 |= (DES_LONG)(((DES_LONG)(*(cp++))) << 8);
            l--;
        }
        l--;
        t0 += z0;
        t0 &= 4294967295L;
        t1 = z1;
        z0 = ((((t0 * t0) & 4294967295L) + ((t1 * t1) & 4294967295L)) & 4294967295L) % 2147483647L;
        z1 = ((t0 * ((t1 + ((DES_LONG)83653421L)) & 4294967295L)) & 4294967295L) % 2147483647L;
    }
    if (lp != ((void *)0)) {
        *lp++ = z0;
        *lp++ = z1;
    }
}
}
