#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — process array from the beginning to min(16, len), but in reverse order
    size_t limit = (16 < len) ? 16 : len;
    size_t i;
    for (i = 0; i < limit; ++i) {
        size_t idx = limit - 1 - i;  // Reverse the index
        out[idx] = in[idx] ^ iv[idx];
    }
}
