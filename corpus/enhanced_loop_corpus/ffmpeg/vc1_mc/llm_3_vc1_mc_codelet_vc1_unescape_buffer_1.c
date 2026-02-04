#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    int indices[256];
    int n = size < 256 ? size : 256;
    for (int i = 0; i < n; i++) {
        indices[i] = (i * 7) % n; // Generate scrambled access pattern
    }
    for (dsize = 0; dsize < n; dsize++) {
        *dst++ = src[indices[dsize]];
    }
    // Handle remaining elements directly if size > 256
    for (; dsize < size; dsize++) {
        *dst++ = src[dsize];
    }
}
