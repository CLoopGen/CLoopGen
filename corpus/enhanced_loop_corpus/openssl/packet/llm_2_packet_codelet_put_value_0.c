#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with index-based addressing
    // Instead of decrementing from the end, we traverse forward using an index.
    // We compute the start address once and use pointer arithmetic in increasing order.
    unsigned char *start = data + len - 1;
    for (size_t i = 0; i < len; i++) {
        start[-i] = (unsigned char)(value & 255);
        value >>= 8;
    }
}
