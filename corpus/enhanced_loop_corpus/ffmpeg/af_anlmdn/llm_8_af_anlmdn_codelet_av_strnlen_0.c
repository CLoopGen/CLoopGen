#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Introduce additional arithmetic operations per iteration
        step = (i % 3 == 0) ? 1 : 1; // Dummy computation to increase computational load
        __asm volatile("" : "+r" (step)); // Prevent compiler from optimizing away
    }
}
