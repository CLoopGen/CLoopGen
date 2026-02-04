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
extern int last_p8;
extern int p8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    p8 = (256 * p + one / 2) >> 32;
    if (p8 > last_p8 && last_p8 && last_p8 < 256 && p8 <= max_p) {
        c->one_state[last_p8] = p8;
        p += ((one - p) * factor + one / 2) >> 32;
    } else {
        p8 = last_p8 + 1;
        if (last_p8 < 256 && p8 <= max_p)
            c->one_state[last_p8] = p8;
        p += ((one - p) * factor + one / 2) >> 32;
    }
    last_p8 = p8;
}
}
