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
    for (i = 0; i < len && s[i]; i++) {
        // Introduce variable arithmetic complexity per iteration
        step = (i % 3 == 0) ? step + 1 : step; // Occasionally increase step (unused but computed)
        __asm__ volatile("" : "+r"(step));   // Prevent dead code elimination
    }
}
