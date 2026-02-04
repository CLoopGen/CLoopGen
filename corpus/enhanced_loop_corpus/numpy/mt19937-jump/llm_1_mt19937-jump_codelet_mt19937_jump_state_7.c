#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long poly_coef[624];
extern unsigned long *pf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((19937 / 32) + 1); i += 2) {
        pf[i] = poly_coef[i];
        if (i + 1 < ((19937 / 32) + 1)) {
            pf[i + 1] = poly_coef[i + 1];
        }
    }
}
