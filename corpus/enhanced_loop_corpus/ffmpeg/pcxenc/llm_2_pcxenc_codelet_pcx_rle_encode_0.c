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



void loop() {
    for (p = 0; p < nplanes; p++) {
        int count = 1;
        const uint8_t *src_plane_base = src + p;
        uint8_t prev = *(src_plane_base);
        for (int offset = nplanes; ; offset += nplanes) {
            const uint8_t *current = src_plane_base + offset;
            if (offset < src_plane_size * nplanes && *current == prev && count < 63) {
                ++count;
            } else {
                if (count != 1 || prev >= 192)
                    *dst++ = 192 | count;
                *dst++ = prev;
                if (offset >= src_plane_size * nplanes)
                    break;
                count = 1;
                prev = *current;
            }
        }
    }
}
