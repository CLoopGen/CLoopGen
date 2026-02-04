#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double cbrt_tab_dbl[8192];
int i;

void init_vars() {
    for (int j = 0; j < 8192; j++) {
        cbrt_tab_dbl[j] = 0.0;
    }
    i = 0;
}