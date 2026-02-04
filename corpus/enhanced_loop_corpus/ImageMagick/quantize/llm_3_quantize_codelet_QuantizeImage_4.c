#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t arr[2];
    ptrdiff_t depth_offset = 0;
    ptrdiff_t colors_offset = 1;
    arr[depth_offset] = 1;
    arr[colors_offset] = colors;
    for (arr[depth_offset] = 1; arr[colors_offset] != 0; arr[depth_offset]++)
        arr[colors_offset] >>= 2;
    depth = arr[0];
    colors = arr[1];
}
