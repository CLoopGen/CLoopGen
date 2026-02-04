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
    const uint8_t *indices = NULL;
    static const size_t access_pattern[] = {0, 2, 4, 6, 1, 3, 5, 7};
    size_t pat_idx = 0;
    for (;;) {
        c->range <<= 8;
        c->low <<= 8;
        ptrdiff_t offset = c->src - c->src_end + access_pattern[pat_idx];
        if (offset >= 0 && offset < (ptrdiff_t)(c->src_end - c->src)) {
            c->low |= c->src[-offset];
            pat_idx = (pat_idx + 1) % 8;
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
