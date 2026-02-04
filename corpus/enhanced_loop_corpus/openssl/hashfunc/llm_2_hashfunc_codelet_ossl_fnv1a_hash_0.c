#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        hash ^= key[i];
        hash *= 1099511628211ULL;
    }
    // Handle odd-length tail if needed
    if (len % 2 == 1) {
        i = len - 1;
        hash ^= key[i];
        hash *= 1099511628211ULL;
    }
}
