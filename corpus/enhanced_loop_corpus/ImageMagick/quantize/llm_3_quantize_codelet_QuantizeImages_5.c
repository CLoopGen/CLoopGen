#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t arr[2];
    ptrdiff_t depth_off = 0;
    ptrdiff_t colors_off = 1;
    arr[depth_off] = 1;
    arr[colors_off] = colors;
    for (arr[depth_off] = 1; arr[colors_off] != 0; arr[depth_off]++)
        arr[colors_off] >>= 2;
    depth = arr[0];
    colors = arr[1];
}
