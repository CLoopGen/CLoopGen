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
    for (size_t block = 0; block < i / 4; ++block) {
        for (int step = 0; step < 4; ++step) {
            x = ((x + 1) & 255);
            tx = d[x];
            y = (tx + y) & 255;
            d[x] = ty = d[y];
            d[y] = tx;
            outdata[step] = d[(tx + ty) & 255] ^ indata[step];
        }
        indata += 4;
        outdata += 4;
        i -= 4;
    }
    for (int remainder = 0; i > 0 && remainder < 4; ++remainder) {
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
