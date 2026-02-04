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



void loop() {
    // Variant 2: Strided memory access with reverse traversal and stride of 2 to alter cache access pattern
    int start = 256 - max_p;
    int end = max_p;
    // Traverse backwards with stride 2 to create non-consecutive access
    for (i = end; i >= start; i -= 2) {
        if (!c->one_state[i]) {
            p = (i * one + 128) >> 8;
            p += ((one - p) * factor + one / 2) >> 32;
            p8 = (256 * p + one / 2) >> 32;
            if (p8 <= i) p8 = i + 1;
            if (p8 > max_p) p8 = max_p;
            c->one_state[i] = p8;
        }
        int j = i - 1; // Process previous element if within bounds
        if (j >= start && !c->one_state[j]) {
            p = (j * one + 128) >> 8;
            p += ((one - p) * factor + one / 2) >> 32;
            p8 = (256 * p + one / 2) >> 32;
            if (p8 <= j) p8 = j + 1;
            if (p8 > max_p) p8 = max_p;
            c->one_state[j] = p8;
        }
    }
}
