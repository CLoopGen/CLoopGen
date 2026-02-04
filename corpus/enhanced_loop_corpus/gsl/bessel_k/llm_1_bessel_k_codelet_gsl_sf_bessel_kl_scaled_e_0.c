#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bkp;
extern double bk;
extern double bkm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j < l; j += 2) {
    if (j + 1 < l) {
        // First iteration step
        bkp = (2 * j + 1) / x * bk + bkm;
        bkm = bk;
        bk = bkp;
        // Second iteration step
        j++;
        bkp = (2 * j + 1) / x * bk + bkm;
        bkm = bk;
        bk = bkp;
    } else {
        bkp = (2 * j + 1) / x * bk + bkm;
        bkm = bk;
        bk = bkp;
    }
}
}
