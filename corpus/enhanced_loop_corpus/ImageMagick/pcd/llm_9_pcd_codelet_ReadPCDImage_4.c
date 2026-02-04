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
    for (i = 0; i < (ssize_t)(((scene) < (5)) ? (scene) : (5)); i += 2) {
        if (i + 1 < (ssize_t)(((scene) < (5)) ? (scene) : (5))) {
            width <<= 1;
            height <<= 1;
        }
    }
}
