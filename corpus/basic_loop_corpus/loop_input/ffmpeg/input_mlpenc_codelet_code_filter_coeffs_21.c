#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int bits;
int shift;
int coeff_mask;

void init_vars() {
    bits = 10;
    shift = 0;
    coeff_mask = 0x00000040; 
}