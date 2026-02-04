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
        if (lp[i][k + 0] == 0) continue;
        if (i > numkeys / 2) {
            lres[0] |= lp[i][k + 0];
            lres[1] |= lp[i][k + 1];
        } else {
            lres[2] |= lp[i][k + 2];
            lres[3] |= lp[i][k + 3];
        }
    }
}
