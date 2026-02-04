#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *access_pattern = (size_t*)malloc(sizeof(size_t) * (length / 256));
    if (!access_pattern) return;
    size_t idx = 0;
    for (extent = 256; extent < length; extent = access_pattern[idx++])
        access_pattern[idx] = extent * 2;
    free(access_pattern);
}
