#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t j = 0; j < (ssize_t)number_planes; j++) {
        for (i = j; i < j + 1 && i < (ssize_t)number_planes; i++) {
            background_color[i] = 0;
        }
    }
}
