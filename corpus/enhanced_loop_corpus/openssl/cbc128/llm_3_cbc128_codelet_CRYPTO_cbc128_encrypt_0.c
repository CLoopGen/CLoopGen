#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index mapping array (reverse order traversal)
    size_t indices[16];
    for (n = 0; n < 16; ++n) {
        indices[n] = 15 - n; // Reverse indexing
    }
    for (n = 0; n < 16; ++n) {
        size_t idx = indices[n];
        out[idx] = in[idx] ^ iv[idx];
    }
}
