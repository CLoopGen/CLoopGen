#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with step size 2, scanning every other character
    size_t step = 2;
    for (i = 0; i < len; i += step) {
        if (!s[i]) {
            break;
        }
    }
    // Resume linear scan from last even index to ensure correct final `i`
    for (; i < len && s[i]; i++);
}
