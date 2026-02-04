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
    for (i = 2; i < numkeys; i += 2) {
        lres[0] |= lp[i][k + 0];
        lres[1] |= lp[i][k + 1];
        lres[2] |= lp[i][k + 2];
        lres[3] |= lp[i][k + 3];

        if (i + 1 < numkeys) {
            lres[0] |= lp[i + 1][k + 0];
            lres[1] |= lp[i + 1][k + 1];
            lres[2] |= lp[i + 1][k + 2];
            lres[3] |= lp[i + 1][k + 3];
        }
    }
}
