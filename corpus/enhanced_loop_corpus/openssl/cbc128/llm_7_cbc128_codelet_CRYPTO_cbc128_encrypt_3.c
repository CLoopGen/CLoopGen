#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = n;
    for (size_t offset = 0; idx < 16; ++offset, ++idx) {
        out[idx] = iv[idx];
        out[idx] ^= 0xFF; // Introduce WAW and modify own write (redundant but creates dependency)
    }
}
