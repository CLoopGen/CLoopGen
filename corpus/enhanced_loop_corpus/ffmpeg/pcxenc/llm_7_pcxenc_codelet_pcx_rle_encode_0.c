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
    uint8_t temp_store = 0;
    for (;; src_plane += nplanes) {
        if (src_plane < src_plane_end) {
            uint8_t curr = *src_plane;
            int is_same = (curr == prev);
            count = is_same ? count + 1 : 1;
            if (!is_same) {
                if (count > 1 || temp_store >= 192)
                    *dst++ = 192 | count;
                *dst++ = temp_store;
                temp_store = curr;
            } else {
                temp_store = prev;
            }
            prev = curr;
        } else {
            if (count != 1 || prev >= 192)
                *dst++ = 192 | count;
            *dst++ = prev;
            break;
        }
    }
}
}
