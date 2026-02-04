#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t coeff_mask;
unsigned int bits;

void init_vars() {
    coeff_mask = 0x3FFF; // All 14 bits set
    bits = 0;
}