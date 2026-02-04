#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive write pattern with block-wise access
    // Instead of writing every element in increasing order, write in blocks of 4 for better spatial locality
    for (i = 1; i < (1 << 13); i += 4) {
        if (i < (1 << 13))           cbrt_tab_dbl[i] = 1;
        if (i + 1 < (1 << 13))       cbrt_tab_dbl[i + 1] = 1;
        if (i + 2 < (1 << 13))       cbrt_tab_dbl[i + 2] = 1;
        if (i + 3 < (1 << 13))       cbrt_tab_dbl[i + 3] = 1;
    }
}
