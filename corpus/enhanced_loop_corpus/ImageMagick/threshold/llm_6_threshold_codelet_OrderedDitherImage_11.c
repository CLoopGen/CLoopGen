#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double levels[64];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        levels[i] = 2.;
        if (i + 1 < 64)
            levels[i + 1] = levels[i]; // Introduces RAW dependency: read after write on 'levels[i]'
    }
}
