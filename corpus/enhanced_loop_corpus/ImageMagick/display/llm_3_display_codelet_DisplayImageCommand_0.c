#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int argc;
extern ssize_t i;
extern size_t *image_marker;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from high to low
    for (i = (ssize_t)argc; i >= 0; i--)
        image_marker[i] = (size_t)argc;
}
