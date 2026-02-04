#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern int shift;
extern int coeff_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (shift = 0; shift < 4 && bits + (shift << 1) < 16 && !(coeff_mask & (1 << shift)) && (coeff_mask & (3 << shift)) != 3; shift++)
        ;
}
