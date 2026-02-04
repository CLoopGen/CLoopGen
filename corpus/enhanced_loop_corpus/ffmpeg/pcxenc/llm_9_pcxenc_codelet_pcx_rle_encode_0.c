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
for (p = 0; p < nplanes; p += 2) {
    for (int plane_offset = 0; plane_offset < 2 && p + plane_offset < nplanes; ++plane_offset) {
        int count = 1;
        const uint8_t *src_plane = src + p + plane_offset;
        const uint8_t *src_plane_end = src_plane + src_plane_size * nplanes;
        uint8_t prev = *src_plane;
        src_plane += nplanes;
        for (; src_plane < src_plane_end; src_plane += nplanes) {
            if (*src_plane == prev && count < 63 && (prev % 2) == 0) {
                ++count;
            } else {
                if (count != 1 || prev >= 192)
                    *dst++ = 192 | count;
                *dst++ = prev;
                count = 1;
                prev = *src_plane;
            }
        }
        if (src_plane >= src_plane_end) {
            *dst++ = 192 | count;
            *dst++ = prev;
        }
    }
}
}
