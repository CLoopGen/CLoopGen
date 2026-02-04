#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t scale_factor_modshift[64];
int i;

void init_vars() {
    // No dynamic allocation needed; arrays are static with fixed size.
    // All variables are already at file scope and will be zero-initialized if needed.
    // The loop uses fixed bounds (0 to 63), so no setup is required for safety.
}