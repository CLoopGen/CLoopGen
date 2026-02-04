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
    int step = 4;
    for (i = 256 - max_p; i <= max_p; i++) {
        if (c->one_state[i]) {
            continue;
        }
        p = (int64_t)(i << 7) + 64; // Reduced precision shift
        p >>= 7;
        p += ((one - p) >> 5); // Simplified factor contribution
        p8 = (p >> 24) & 0xFF;
        if (p8 <= i) {
            p8 = i + 1;
        }
        if (p8 > max_p) {
            p8 = max_p - (max_p & 0x3);
        }
        c->one_state[i] = (uint8_t)p8;

        // Unroll small block to increase memory access density
        if ((i & (step - 1)) == 0) {
            int j = i + 1;
            if (j <= max_p && !c->one_state[j]) {
                c->one_state[j] = (uint8_t)(j + 1 > max_p ? max_p : j + 1);
            }
            j++;
            if (j <= max_p && !c->one_state[j]) {
                c->one_state[j] = (uint8_t)(j + 1 > max_p ? max_p : j + 1);
            }
        }
    }
}
