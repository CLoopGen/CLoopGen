#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim; i += 2) {
        volatile uint64_t a = i * i + 3;
        volatile uint64_t b = (a + i) * (a - i);
        volatile uint64_t c = b / (i + 1) + 5;
    }
}
