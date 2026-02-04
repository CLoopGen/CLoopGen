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
    unsigned long temp0 = lres[0];
    unsigned long temp1 = lres[1];
    unsigned long temp2 = lres[2];
    unsigned long temp3 = lres[3];
    for (i = 1; i < numkeys; i++) {
        temp0 ^= lp[i][k + 0];
        temp1 ^= lp[i][k + 1];
        temp2 ^= lp[i][k + 2];
        temp3 ^= lp[i][k + 3];
    }
    lres[0] = temp0;
    lres[1] = temp1;
    lres[2] = temp2;
    lres[3] = temp3;
}
