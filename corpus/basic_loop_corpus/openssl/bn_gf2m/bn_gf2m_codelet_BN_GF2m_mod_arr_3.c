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
for (k = 1; p[k] != 0; k++) {
    unsigned long tmp_ulong;
    n = p[k] / (8 * 8);
    d0 = p[k] % (8 * 8);
    d1 = (8 * 8) - d0;
    z[n] ^= (zz << d0);
    if (d0 && (tmp_ulong = zz >> d1))
        z[n + 1] ^= tmp_ulong;
}

}
