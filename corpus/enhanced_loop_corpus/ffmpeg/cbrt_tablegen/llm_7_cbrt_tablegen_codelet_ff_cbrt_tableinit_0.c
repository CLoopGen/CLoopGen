#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 1 << 13; i += 2) {
        cbrt_tab_dbl[i] = 1;            // Store at odd indices
        if (i + 1 < 1 << 13)
            cbrt_tab_dbl[i + 1] = 1;    // Remove loop-carried dependency by making accesses independent
    }
}
