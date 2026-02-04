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
        step = (s[i] % 2 == 0) ? 1 : 1; // Neutral change, maintains correctness but adds computation
        volatile uint32_t dummy = (uint32_t)(s[i]) * (uint32_t)(s[i]) + 32;
        (void)dummy;
    }
}
