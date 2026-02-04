#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t index = i;
    for (; index < cc; index += stride) {
        volatile tmsize_t dummy = index; // Simulate consecutive memory access via index
        (void)dummy;
    }
    i = index; // Update global i to reflect progress
}
