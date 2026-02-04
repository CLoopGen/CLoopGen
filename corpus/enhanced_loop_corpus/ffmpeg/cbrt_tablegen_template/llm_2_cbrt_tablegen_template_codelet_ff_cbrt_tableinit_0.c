#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive write access with unrolled loop (stride-2 access pattern)
    for (i = 1; i < 1 << 13; i += 2) {
        cbrt_tab_dbl[i] = 1;
        if (i + 1 < 1 << 13) {
            cbrt_tab_dbl[i + 1] = 1;
        }
    }
}
