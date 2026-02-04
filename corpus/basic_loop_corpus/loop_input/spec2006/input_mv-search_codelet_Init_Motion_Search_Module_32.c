#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *refbits;
int bits;
int i;
int imin;
int imax;
int max_ref_bits;

void init_vars() {
    max_ref_bits = 31;
    size_t array_size = (1 << ((max_ref_bits >> 1) + 1));
    refbits = (int*)calloc(array_size, sizeof(int));
}
