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
        // Introduce dummy operations to increase per-iteration computation
        step = 1; // Redundant assignment to simulate variable computational load
        volatile size_t dummy = i * i + 2 * i + 1; // Additional arithmetic intensity
        (void)dummy;
    }
}
