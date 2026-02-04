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
for (i = 0; i < (out_count > 4 ? 4 : out_count); i++) {
    cp = input;
    l = (length + 1) / 2; // Process two bytes per iteration, rounded up
    for (long j = 0; j < l; j++) {
        t0 = (j*2 < length) ? (DES_LONG)(input[j*2]) : 0;
        t0 |= (j*2+1 < length) ? (DES_LONG)(input[j*2+1]) << 8 : 0;
        t0 += z0;
        t0 &= 4294967295L;
        t1 = z1;
        DES_LONG sq_t0 = (t0 * t0) & 4294967295L;
        DES_LONG sq_t1 = (t1 * t1) & 4294967295L;
        z0 = ((sq_t0 + sq_t1) & 4294967295L) % 2147483647L;
        z1 = (t0 * ((t1 + 83653421L) & 4294967295L)) % 2147483647L;
    }
    if (lp != NULL) {
        lp[0] = z0;
        lp[1] = z1;
        lp += 2;
    }
}
}
