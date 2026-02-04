#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long poly_coef[624];
extern unsigned long *pf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp;
    for (i = 0; i < ((19937 / 32) + 1); i++) {
        temp = poly_coef[i];
        pf[i] = temp;
    }
}
