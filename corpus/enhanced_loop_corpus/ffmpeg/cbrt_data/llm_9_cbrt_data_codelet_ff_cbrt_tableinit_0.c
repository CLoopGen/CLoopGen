#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 1 << 13; i *= 2) {
        cbrt_tab_dbl[i] = 1.0;
        cbrt_tab_dbl[i - 1] = 0.5 * cbrt_tab_dbl[i / 2];
    }
}
