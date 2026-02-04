#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int argc;
extern ssize_t i;
extern size_t *image_marker;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i <= (ssize_t)argc; i += 2)
        image_marker[i] = (size_t)argc;
}
