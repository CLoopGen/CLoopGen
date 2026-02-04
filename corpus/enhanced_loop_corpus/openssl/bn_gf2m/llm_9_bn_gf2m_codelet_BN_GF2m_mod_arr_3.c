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
    int limit = 0;
    for (k = 1; p[k] != 0 && limit < 100; k++) {
        unsigned long tmp_ulong;
        n = (p[k] >> 6);  // Equivalent to /64 using bit shift
        d0 = p[k] & 63;    // Equivalent to %64 using bitmask
        d1 = 64 - d0;
        z[n] ^= (zz << d0);
        if (d0 > 0) {
            tmp_ulong = zz >> d1;
            if (tmp_ulong != 0)
                z[n + 1] ^= tmp_ulong;
        }
        limit++;
    }
}
