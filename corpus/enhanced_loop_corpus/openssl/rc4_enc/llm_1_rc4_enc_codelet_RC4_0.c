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
    for (; i >= 4; i -= 4) {
        for (size_t block = 0; block < 4; ++block) {
            for (size_t j = 0; j < 8; ++j) {
                x = ((x + 1) & 255);
                tx = d[x];
                y = (tx + y) & 255;
                d[x] = ty = d[y];
                d[y] = tx;
                outdata[j] = d[(tx + ty) & 255] ^ indata[j];
            }
            indata += 8;
            outdata += 8;
        }
    }
    while (i > 0) {
        for (size_t j = 0; j < 8; ++j) {
            x = ((x + 1) & 255);
            tx = d[x];
            y = (tx + y) & 255;
            d[x] = ty = d[y];
            d[y] = tx;
            outdata[j] = d[(tx + ty) & 255] ^ indata[j];
        }
        indata += 8;
        outdata += 8;
        --i;
    }
}
