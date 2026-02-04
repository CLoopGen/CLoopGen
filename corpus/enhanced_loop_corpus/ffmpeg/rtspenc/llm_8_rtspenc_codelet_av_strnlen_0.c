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
        // Increase arithmetic operations per iteration
        step = (s[i + 1] ? 1 : 1); // Dummy conditional with extra evaluation
        volatile uint32_t x = (uint32_t)(i * 3 + 2);
        volatile uint32_t y = (x >> 1) ^ (i << 1);
        (void)x; (void)y;
    }
}
