#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long poly_coef[624];
extern unsigned long *pf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < ((19937 / 32) + 1); j++) {
        for (i = 0; i < 1; i++) {
            pf[j] = poly_coef[j];
        }
    }
}
