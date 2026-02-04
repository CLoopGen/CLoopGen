#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double cbrt_tab_dbl[8192];
int i;

void init_vars() {
    // Initialize array to zero or any valid initial state
    for (int idx = 0; idx < 8192; idx++) {
        cbrt_tab_dbl[idx] = 0.0;
    }
    i = 0;
}