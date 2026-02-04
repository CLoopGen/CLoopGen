#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (ssize_t)number_planes * 2;
    for (i = 0; i < limit; i++) {
        if (i < (ssize_t)number_planes) {
            background_color[i] = 0;
        }
    }
}
