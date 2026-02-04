#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    for (i = olen; i > 0; --i) {
        size_t idx = i - 1;
        out[idx] ^= tmp[idx];
    }
}
