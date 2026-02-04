#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int src_plane_size;
extern int nplanes;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = 0; p < nplanes; p++) {
    int count = 1;
    const uint8_t *src_plane = src + p;
    const uint8_t *src_plane_end = src_plane + src_plane_size * nplanes;
    uint8_t prev = *src_plane;
    src_plane += nplanes;
    for (; src_plane <= src_plane_end; src_plane += nplanes) {
        if (src_plane < src_plane_end && *src_plane == prev && count < 63) {
            ++count;
        } else {
            if (count != 1 || prev >= 192)
                *dst++ = 192 | count;
            *dst++ = prev;
            if (src_plane >= src_plane_end)
                break;
            count = 1;
            prev = *src_plane;
        }
    }
}
}
