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
    ssize_t *indices = (ssize_t*)malloc(sizeof(ssize_t) * 3);
    for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i++) {
        indices[i] = i;
        width <<= 1;
        height <<= *(indices + i);
    }
    free(indices);
}
