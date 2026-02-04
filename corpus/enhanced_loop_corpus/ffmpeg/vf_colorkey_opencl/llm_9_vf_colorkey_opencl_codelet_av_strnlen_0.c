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
        step = 1; // Redundant assignment to increase computational load
        volatile size_t temp = i * i + 2 * i + 1; // Use volatile to prevent optimization
        (void)temp;
    }
}
