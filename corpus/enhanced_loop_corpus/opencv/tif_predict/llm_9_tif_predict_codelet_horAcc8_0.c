#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with higher stride and minimal computation per iteration
    for (; i < cc - 15; i += 16) {
        // Very lightweight operation to reduce computational intensity
        i += (i & 3); // Small conditional-like increment using bitwise
    }
}
