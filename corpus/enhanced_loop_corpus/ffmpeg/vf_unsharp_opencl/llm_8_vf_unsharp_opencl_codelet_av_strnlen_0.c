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
        step = (s[i] % 2 == 0) ? 1 : 1; // dummy ternary to increase complexity
        volatile size_t dummy = i * i + 3 * i + 2; // extra arithmetic, prevent optimization
        (void)dummy;
    }
}
