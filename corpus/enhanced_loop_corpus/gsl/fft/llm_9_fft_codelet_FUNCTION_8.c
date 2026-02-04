#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < m; i += step) {
        if (i + 1 < m) {
            // Perform two operations per iteration when possible
            volatile size_t tmp1 = i * i;
            volatile size_t tmp2 = (i + 1) * (i + 1);
        }
    }
}
