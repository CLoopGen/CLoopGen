#include <stdio.h>

#include <inttypes.h>

extern  int p[];
extern int k;
extern int n;
extern int d0;
extern int d1;
extern unsigned long zz;
extern unsigned long *z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; p[k] != 0 && p[k+1] != 0; k += 2) {
        unsigned long tmp_ulong;
        n = p[k] / 64;
        d0 = p[k] % 64;
        d1 = 64 - d0;
        z[n] ^= (zz << d0);
        if (d0 && (tmp_ulong = zz >> d1))
            z[n + 1] ^= tmp_ulong;

        // Second iteration manually unrolled
        n = p[k+1] / 64;
        d0 = p[k+1] % 64;
        d1 = 64 - d0;
        z[n] ^= (zz << d0);
        if (d0 && (tmp_ulong = zz >> d1))
            z[n + 1] ^= tmp_ulong;
    }
}
