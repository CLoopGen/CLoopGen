#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long poly_coef[624];
extern unsigned long *pf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((19937 / 32) + 1); i++) {
        pf[i] = (i % 3 == 0) ? poly_coef[i] : 0UL;
    }
}
