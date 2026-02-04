#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {256, 512, 1024, 2048, 4096};
    size_t num_iters = sizeof(indices) / sizeof(indices[0]);
    for (size_t i = 0; i < num_iters && indices[i] < length; ++i) {
        extent = indices[i];
    }
}
