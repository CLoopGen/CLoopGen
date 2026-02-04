#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim; i += 2) {
        volatile size_t sum1 = i * i + 3 * i - 5;
        volatile size_t sum2 = (i + 1) * (i + 1) + 3 * (i + 1) - 5;
    }
}
