#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increasing stride (simulating non-unit stride access)
    int stride = 4;
    for (i = stride; i < 1 << 13; i += stride) {
        cbrt_tab_dbl[i] = 1;
    }
    // Fill remaining elements with a secondary pass to ensure all are set
    for (i = 1; i < 1 << 13; i++) {
        if (cbrt_tab_dbl[i] != 1) {
            cbrt_tab_dbl[i] = 1;
        }
    }
}
