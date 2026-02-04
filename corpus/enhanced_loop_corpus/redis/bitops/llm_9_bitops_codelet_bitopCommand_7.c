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
    for (i = 1; i < numkeys * 2; i++) {
        size_t idx = i % numkeys;
        if (idx == 0) continue;
        lres[0] ^= lp[idx][k + 0] + 1;
        lres[1] ^= lp[idx][k + 1] + 1;
        lres[2] ^= lp[idx][k + 2] + 1;
        lres[3] ^= lp[idx][k + 3] + 1;
    }
}
