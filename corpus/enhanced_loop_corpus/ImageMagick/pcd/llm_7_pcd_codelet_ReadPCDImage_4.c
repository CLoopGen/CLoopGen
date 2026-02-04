#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t height;
extern size_t scene;
extern size_t width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_width = width;
    size_t local_height = height;
    for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i++) {
        local_width <<= 1;
        local_height <<= 1;
    }
    width = local_width;  // Eliminate loop-carried dependency on global width
    height = local_height; // Eliminate loop-carried dependency on global height
}
