#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cbrt_tab_dbl[8192];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 1; i < 1 << 13; i++) {
        temp = cbrt_tab_dbl[i - 1]; // Introduce RAW dependency: current iteration reads previous write
        cbrt_tab_dbl[i] = temp + 1.0; // WAW and RAW: depends on prior iteration's result
    }
}
