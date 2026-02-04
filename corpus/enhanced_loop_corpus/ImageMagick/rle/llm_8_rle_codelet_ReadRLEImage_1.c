#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)number_planes; i += 2) {
        if (i < (ssize_t)number_planes) background_color[i] = 0;
        if (i + 1 < (ssize_t)number_planes) background_color[i + 1] = 0;
    }
}
