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
    for (;;) {
        // Variant 1: Consecutive memory access with prefetching and coalesced operations
        unsigned int temp_x = x;
        for (int j = 0; j < 8; ++j) {
            temp_x = (temp_x + 1) & 255;
            tx = d[temp_x];
            y = (tx + y) & 255;
            d[temp_x] = ty = d[y];
            d[y] = tx;
            outdata[j] = d[(tx + ty) & 255] ^ indata[j];
        }
        x = temp_x;
        indata += 8;
        outdata += 8;
        if (--i == 0)
            break;
    }
}
