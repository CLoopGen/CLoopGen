#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t scale_factor_modshift[64];
int i;

void init_vars() {
    // No dynamic initialization required since array size is fixed and loop uses hardcoded bounds
}