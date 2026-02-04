#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long numkeys;
extern unsigned long i;
extern unsigned long **lp;
extern unsigned long *lres;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < numkeys; i++) {
        unsigned long val0 = lp[i][k + 0];
        unsigned long val1 = lp[i][k + 1];
        unsigned long val2 = lp[i][k + 2];
        unsigned long val3 = lp[i][k + 3];
        lres[0] |= val0;
        lres[1] |= val1;
        lres[2] |= val2;
        lres[3] |= val3;
    }
}
