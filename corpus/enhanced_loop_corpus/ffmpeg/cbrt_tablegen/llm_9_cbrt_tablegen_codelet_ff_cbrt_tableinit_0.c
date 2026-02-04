#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 1 << 12; i++) {
        double x = (double)i;
        cbrt_tab_dbl[i] = x * x * x - 3.0 * x + 2.0;
        cbrt_tab_dbl[i] = cbrt_tab_dbl[i] > 0 ? cbrt_tab_dbl[i] : -cbrt_tab_dbl[i];
    }
}
