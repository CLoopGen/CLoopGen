#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t stride = 0; stride < 16; stride += 4)
        for (size_t offset = 0; offset < 4 && n + stride + offset < 16; ++offset)
            ivec[n + stride + offset] = in[n + stride + offset];
}
