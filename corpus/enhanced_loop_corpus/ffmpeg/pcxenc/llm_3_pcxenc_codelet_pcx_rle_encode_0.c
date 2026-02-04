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
        uint8_t local_buffer[64];
        int buf_idx = 0;
        for (int i = p; i < src_plane_size * nplanes; i += nplanes) {
            uint8_t current_val = src[i];
            if (buf_idx > 0 && current_val == local_buffer[buf_idx - 1] && count < 63) {
                ++count;
            } else {
                if (buf_idx > 0) {
                    if (count != 1 || local_buffer[buf_idx - 1] >= 192)
                        *dst++ = 192 | count;
                    *dst++ = local_buffer[buf_idx - 1];
                }
                count = 1;
                local_buffer[buf_idx] = current_val;
                buf_idx = 1;
            }
        }
        if (buf_idx > 0) {
            if (count != 1 || local_buffer[0] >= 192)
                *dst++ = 192 | count;
            *dst++ = local_buffer[0];
        }
    }
}
