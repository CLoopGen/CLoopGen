#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RangeCoder {
    const uint8_t *src;
    const uint8_t *src_end;
    uint32_t range;
    uint32_t low;
    int got_error;
} RangeCoder;

extern RangeCoder *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t buffer[8];
    int buf_idx = 0;
    for (;;) {
        c->range <<= 8;
        c->low <<= 8;
        if (buf_idx == 0 && c->src < c->src_end) {
            size_t bytes_to_read = (c->src_end - c->src) >= 8 ? 8 : (c->src_end - c->src);
            for (int i = 0; i < bytes_to_read; ++i) {
                buffer[i] = c->src[i];
            }
            c->src += bytes_to_read;
            buf_idx = bytes_to_read;
        }
        if (buf_idx > 0) {
            c->low |= buffer[--buf_idx];
        } else if (!c->low) {
            c->got_error = 1;
            c->low = 1;
        }
        if (c->low > c->range) {
            c->got_error = 1;
            c->low = 1;
        }
        if (c->range >= 16777216)
            return;
    }
}
