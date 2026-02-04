#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index mapping array
    size_t indices[15];
    for (i = 0; i < 15; i++) {
        indices[i] = 14 - i;  // reverse order access
    }
    for (i = 0; i < 15; i++) {
        scale_abs[indices[i]] = 1.;
    }
}
