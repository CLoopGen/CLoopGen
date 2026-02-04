#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        // Increase arithmetic operations per iteration
        step = (s[i + 1] ? 1 : 1); // dummy pattern to increase computation without changing logic
        __asm volatile("" : "+r" (i)); // simulate extra work, prevents over-optimization
    }
}
