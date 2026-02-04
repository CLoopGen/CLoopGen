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
if (i < (ssize_t)(((scene) < (3)) ? (scene) : (3))) {
    for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i += 2) {
        width <<= 1;
        height <<= 1;
        if (i + 1 < (ssize_t)(((scene) < (3)) ? (scene) : (3))) {
            width <<= 1;
            height <<= 1;
        }
    }
}
}
