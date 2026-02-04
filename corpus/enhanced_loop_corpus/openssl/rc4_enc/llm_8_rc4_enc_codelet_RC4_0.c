#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *indata;
extern unsigned char *outdata;
extern unsigned int *d;
extern unsigned int x;
extern unsigned int y;
extern unsigned int tx;
extern unsigned int ty;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i > 0; i--) {
    for (size_t unroll = 0; unroll < 8; ++unroll) {
        x = (x + 1) & 255;
        tx = d[x];
        y = (tx + y) & 255;
        unsigned int temp = d[y];
        d[x] = d[y];
        d[y] = tx;
        ty = temp;
        outdata[unroll] = d[(tx + ty) & 255] ^ indata[unroll];
    }
    indata += 8;
    outdata += 8;
}
}
