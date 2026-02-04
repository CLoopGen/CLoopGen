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
    if (numkeys > 1) {
        for (size_t j = 0; j < 4; j++) {
            for (i = 1; i < numkeys; i++) {
                lres[j] ^= lp[i][k + j];
            }
        }
    }
}
