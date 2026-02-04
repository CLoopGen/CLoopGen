#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step through Rows (access every 2nd element in a strided pattern, then handle remainder)
    acc = 0;
    int step = 2;
    // First pass: process even indices
    for (y = 0; y < 16; y++) {
        for (x = 0; x < 16; x += step) {
            int offset = x + y * stride;
            int diff = src[offset] - ref;
            acc += (diff >= 0) ? diff : -diff;
        }
    }
    // Second pass: process odd indices (true strided variant with non-contiguous access)
    for (y = 0; y < 16; y++) {
        for (x = 1; x < 16; x += step) {
            int offset = x + y * stride;
            int diff = src[offset] - ref;
            acc += (diff >= 0) ? diff : -diff;
        }
    }
}
