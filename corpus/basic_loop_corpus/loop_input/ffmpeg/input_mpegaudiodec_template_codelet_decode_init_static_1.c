#include <stdint.h>
#include <stdlib.h>

uint16_t scale_factor_modshift[64];
int i;

void init_vars() {
    // No dynamic initialization needed; static arrays are zero-initialized by default
    // The loop uses fixed bounds (0 to 63), which are within array size
}