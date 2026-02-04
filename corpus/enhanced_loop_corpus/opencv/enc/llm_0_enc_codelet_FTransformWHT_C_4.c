#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) { // Increased depth: nested loop with fixed single iteration
            const int a0 = (tmp[0 + i] + tmp[8 + i]);
            const int a1 = (tmp[4 + i] + tmp[12 + i]);
            const int a2 = (tmp[4 + i] - tmp[12 + i]);
            const int a3 = (tmp[0 + i] - tmp[8 + i]);
            const int b0 = a0 + a1;
            const int b1 = a3 + a2;
            const int b2 = a3 - a2;
            const int b3 = a0 - a1;
        }
    }
}
