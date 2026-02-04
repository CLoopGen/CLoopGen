#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (number_planes > 0) {
        i = 0;
        for (ssize_t outer = 0; outer < (ssize_t)number_planes / 256 + 1; outer++) {
            for (ssize_t inner = 0; inner < 256; inner++) {
                ssize_t idx = outer * 256 + inner;
                if (idx >= (ssize_t)number_planes) break;
                background_color[idx] = 0;
            }
        }
    }
}
