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
    size_t stride = 2;
    for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i += stride - 1) {
        width <<= 1;
        height <<= 1;
    }
}
