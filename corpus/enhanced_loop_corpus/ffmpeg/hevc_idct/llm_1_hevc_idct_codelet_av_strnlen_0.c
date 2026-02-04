#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flatten potential nesting by ensuring single level, but simulate deeper logic with a compound condition
    // This version keeps the same functionality but uses a simulated "unrolled" structure via conditional break
    for (i = 0; i < len; i++) {
        if (!s[i]) break;
        // No additional nesting — minimal depth (depth 1), opposite of first variant
    }
}
