#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (i = 1; i < 1 << 13; i++) {
        temp = cbrt_tab_dbl[i-1] + 1.0;  // Introduce RAW dependency: current iteration reads previous write
        cbrt_tab_dbl[i] = temp;         // WAW dependency removed by using temp, but loop-carried RAW introduced
    }
}
