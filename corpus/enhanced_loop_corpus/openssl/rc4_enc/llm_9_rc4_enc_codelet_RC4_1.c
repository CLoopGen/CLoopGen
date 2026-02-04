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
    size_t limit = (i / 4) * 4;
    for (size_t j = 0; j < limit; j += 4) {
        x = (x + 1) & 255; tx = d[x]; y = (tx + y) & 255; d[x] = ty = d[y]; d[y] = tx;
        outdata[j] = d[(tx + ty) & 255] ^ indata[j];

        x = (x + 1) & 255; tx = d[x]; y = (tx + y) & 255; d[x] = ty = d[y]; d[y] = tx;
        outdata[j+1] = d[(tx + ty) & 255] ^ indata[j+1];

        x = (x + 1) & 255; tx = d[x]; y = (tx + y) & 255; d[x] = ty = d[y]; d[y] = tx;
        outdata[j+2] = d[(tx + ty) & 255] ^ indata[j+2];

        x = (x + 1) & 255; tx = d[x]; y = (tx + y) & 255; d[x] = ty = d[y]; d[y] = tx;
        outdata[j+3] = d[(tx + ty) & 255] ^ indata[j+3];
    }
    for (size_t j = limit; j < i; ++j) {
        x = (x + 1) & 255;
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[j] = d[(tx + ty) & 255] ^ indata[j];
    }
}
