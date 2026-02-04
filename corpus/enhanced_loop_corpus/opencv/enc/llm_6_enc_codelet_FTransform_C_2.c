#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        const int a0 = (tmp[0 + i] + tmp[12 + i]);
        const int a1 = (tmp[4 + i] + tmp[8 + i]);
        const int a2 = (a1 - 2 * tmp[8 + i]); // Introduces dependency on a1 (RAW: read after write)
        const int a3 = (a0 - 2 * tmp[12 + i]); // Introduces dependency on a0
    }
}
