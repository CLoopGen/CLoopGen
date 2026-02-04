#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int argc;
extern ssize_t i;
extern size_t *image_marker;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (j = 0; j <= i; j++)
        image_marker[j] = (size_t)argc;
}
