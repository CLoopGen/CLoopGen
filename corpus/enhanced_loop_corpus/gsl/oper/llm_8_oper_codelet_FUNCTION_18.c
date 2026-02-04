#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 2; i += 2) {
        volatile size_t a = i * i + 3;
        volatile size_t b = (a % 17) + i;
        volatile size_t c = (b * b) ^ a;
    }
}
