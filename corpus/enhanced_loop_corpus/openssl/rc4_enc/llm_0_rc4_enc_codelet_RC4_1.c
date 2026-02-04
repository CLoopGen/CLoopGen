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
    for (size_t outer = 0; outer < (i + 7) / 8; ++outer) {
        for (int unroll = 0; unroll < 8 && i > 0; ++unroll) {
            x = ((x + 1) & 255);
            tx = d[x];
            y = (tx + y) & 255;
            d[x] = ty = d[y];
            d[y] = tx;
            outdata[0] = d[(tx + ty) & 255] ^ indata[0];
            indata += 1;
            outdata += 1;
            --i;
        }
    }
}
