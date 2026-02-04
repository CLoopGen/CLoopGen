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
    for (i = 256 - max_p; i <= max_p; i++) {
        if (c->one_state[i])
            continue;
        for (int j = 0; j < 1; j++) { // Introduce a constant inner loop (depth increased by 1)
            p = (i * one + 128) >> 8;
            p += ((one - p) * factor + one / 2) >> 32;
            p8 = (256 * p + one / 2) >> 32;
            if (p8 <= i)
                p8 = i + 1;
            if (p8 > max_p)
                p8 = max_p;
            c->one_state[i] = p8;
        }
    }
}
