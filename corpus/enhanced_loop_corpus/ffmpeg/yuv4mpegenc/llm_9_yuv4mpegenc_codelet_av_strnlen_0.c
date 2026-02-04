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
        // Increase computational intensity by adding dummy operations
        step = (i % 3 == 0) ? 1 : step;  // Re-read step to increase work per iteration
        __asm__ volatile("" : "+r" (step)); // Prevent optimization, add computational load
    }
}
