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
        step = (s[i + 1] % 7) + 1;  // Adaptive step based on next character, ensures step >= 1
        len -= (len > 10) ? 1 : 0;  // Slightly reduce len under condition to vary trip count
    }
}
