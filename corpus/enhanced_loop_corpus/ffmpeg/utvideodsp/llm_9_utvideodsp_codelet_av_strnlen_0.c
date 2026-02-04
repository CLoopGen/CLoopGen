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
        // Increase computational intensity with arithmetic operations
        step = (i % 3 == 0) ? 1 : ((i % 5 == 0) ? 2 : 1); // Vary step size based on modulo conditions
        // Additional arithmetic to increase per-iteration cost
        volatile size_t dummy = (i * i + 3*i + 1) / (i + 1);
    }
}
