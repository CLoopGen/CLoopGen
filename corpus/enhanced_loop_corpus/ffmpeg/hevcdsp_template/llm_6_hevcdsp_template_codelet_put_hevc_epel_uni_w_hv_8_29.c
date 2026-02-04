#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t local_filter[4];
    for (y = 0; y < height + 3; y++) {
        // Introduce local copy of filter to break potential WAR/WAW on global filter
        for (int k = 0; k < 4; k++) {
            local_filter[k] = filter[k];
        }
        for (x = 0; x < width; x++) {
            // Reorder memory accesses and introduce temporary variable to alter RAW pattern
            int16_t sum = 0;
            sum += local_filter[0] * src[x - 1];
            sum += local_filter[1] * src[x];
            sum += local_filter[2] * src[x + 1];
            sum += local_filter[3] * src[x + 2];
            tmp[x] = sum >> 8; // Same shift, made explicit
        }
        src += srcstride;
        tmp += 64;
    }
}
