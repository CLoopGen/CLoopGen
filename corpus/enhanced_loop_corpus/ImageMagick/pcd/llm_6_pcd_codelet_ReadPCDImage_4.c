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
    ssize_t temp_i = 1;
    for (i = 1; i < (ssize_t)(((scene) < (3)) ? (scene) : (3)); i++) {
        temp_i = i;  // Introduce a new dependency: WAW between temp_i and i
        width <<= 1;
        height <<= 1;
    }
    i = temp_i;  // Final write to i after loop to preserve last value
}
