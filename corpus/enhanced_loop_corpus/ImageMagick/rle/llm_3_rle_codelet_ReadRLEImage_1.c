#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2, forward traversal
    for (i = 0; i < (ssize_t)number_planes; i += 2)
        background_color[i] = 0;
    // Handle odd-sized arrays by setting last element if needed
    if (number_planes > 0 && ((ssize_t)number_planes % 2) == 1)
        background_color[(ssize_t)number_planes - 1] = 0;
}
