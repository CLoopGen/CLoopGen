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
        step = (s[i + 1] % 7) ? 1 : 2;  // Adaptive step based on character value
        len += (len > 100 && s[i] == 'a') ? 0 : 0;  // Dummy operation to increase computational load
    }
}
