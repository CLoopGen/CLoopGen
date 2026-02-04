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
for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i++) {
    if (i % 2 == 0) {
        width <<= 1;
    } else {
        height <<= 1;
    }
}
}
