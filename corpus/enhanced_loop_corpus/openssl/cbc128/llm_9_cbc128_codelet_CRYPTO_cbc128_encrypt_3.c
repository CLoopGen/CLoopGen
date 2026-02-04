#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = n; i < 16; i += 2) {
        out[i] = iv[i];
        if (i + 1 < 16)
            out[i + 1] = iv[i + 1] ^ 0xFF;  // Every other byte is bitwise inverted
    }
    n = i;  // Update n to indicate partial completion
}
