#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t max_projection;
extern size_t *projection;
extern size_t width;
extern ssize_t i;
extern ssize_t skew;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t temp_skew = 0;
    size_t temp_max = max_projection;
    for (i = 0; i < (ssize_t)(2 * width - 1); i++) {
        size_t current_proj = projection[i];
        if (current_proj > temp_max) {
            temp_max = current_proj;
            temp_skew = i - (ssize_t)width + 1;
        }
    }
    max_projection = temp_max;
    skew = temp_skew;
}
