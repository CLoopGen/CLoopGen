#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Traverse the array with a stride of 8 to simulate non-consecutive access
    int stride = 8;
    for (i = stride; i < (1 << 13); i += stride) {
        cbrt_tab_dbl[i] = 1;
    }
    // Handle remaining elements not covered by the stride
    for (i = 1; i < stride; i++) {
        cbrt_tab_dbl[i] = 1;
    }
}
