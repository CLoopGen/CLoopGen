#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t local_filter[4];
    for (y = 0; y < height + 3; y++) {
        // Introduce temporary local copy of filter to modify data dependency
        // This removes potential aliasing and creates a local RAW dependency
        for (int i = 0; i < 4; i++) {
            local_filter[i] = filter[i];
        }
        for (x = 0; x < width; x++) {
            // Reorder computation slightly and use local_filter to break global dependency on 'filter'
            int16_t val = (local_filter[0] * src[x - 1] +
                           local_filter[1] * src[x] +
                           local_filter[2] * src[x + 1] +
                           local_filter[3] * src[x + 2]) >> 4;
            tmp[x] = val;
        }
        src += srcstride;
        tmp += 64;
    }
}
