#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RangeCoder {
    int low;
    int range;
    int outstanding_count;
    int outstanding_byte;
    uint8_t zero_state[256];
    uint8_t one_state[256];
    uint8_t *bytestream_start;
    uint8_t *bytestream;
    uint8_t *bytestream_end;
    int overread;
} RangeCoder;

extern RangeCoder *c;
extern int factor;
extern int max_p;
extern  int64_t one;
extern int64_t p;
extern int p8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 256 - max_p; i <= max_p; i += 2) {
        if (c->one_state[i])
            continue;
        p = (i * one + 128) >> 8;
        p += ((one - p) * factor + one / 2) >> 31;
        p8 = (512 * p + one / 2) >> 32;
        if (p8 <= i)
            p8 = i + 2;
        if (p8 > max_p)
            p8 = max_p;
        c->one_state[i] = p8;
        if (i + 1 <= max_p && !c->one_state[i + 1]) {
            p = ((i + 1) * one + 128) >> 8;
            p += ((one - p) * factor + one / 2) >> 31;
            p8 = (512 * p + one / 2) >> 32;
            if (p8 <= i + 1)
                p8 = i + 3;
            if (p8 > max_p)
                p8 = max_p;
            c->one_state[i + 1] = p8;
        }
    }
}
