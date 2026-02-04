#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = n;
    for (size_t offset = 0; offset < 16 - n && idx < 16; ++offset) {
        ivec[idx] = in[idx];
        idx += 1;
    }
    n = idx;
}
