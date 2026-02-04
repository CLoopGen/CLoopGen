#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int naxes = 64;
int axes[64];

void init_vars() {
    // No dynamic allocation needed; static array is already sized to naxes
    // Ensure naxes does not exceed the fixed size of axes (64)
    if (naxes > 64) {
        naxes = 64;
    }
}