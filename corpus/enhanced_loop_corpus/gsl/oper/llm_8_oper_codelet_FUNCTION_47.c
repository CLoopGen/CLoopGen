#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 2; i += 2) {
        volatile size_t x = i * i + i - 1;
        volatile size_t y = (x + i) / 2;
    }
}
