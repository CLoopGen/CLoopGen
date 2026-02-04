#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim; i += 2) {
        volatile size_t x = i * i + 3 * i - 5;
        volatile size_t y = (i + 1) * (i - 1);
    }
}
