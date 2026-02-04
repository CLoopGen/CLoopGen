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
    for (size_t batch = 0; batch < 32; ++batch) {
        x = (x + 1) & 255;
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        size_t idx = (tx + ty) & 255;
        outdata[0] = d[idx] ^ indata[0];
        indata++;
        outdata++;
    }
}
while (i > 0) {
    x = (x + 1) & 255;
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    outdata[0] = d[(tx + ty) & 255] ^ indata[0];
    indata++;
    outdata++;
    --i;
}
}
