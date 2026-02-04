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
        // Variant 2: Strided memory access with increasing stride to simulate non-unit access
        // Access indata and outdata with a fixed stride of 2 to create a strided pattern
        const size_t stride = 2;
        
        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[0 * stride] = d[(tx + ty) & 255] ^ indata[0 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[1 * stride] = d[(tx + ty) & 255] ^ indata[1 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[2 * stride] = d[(tx + ty) & 255] ^ indata[2 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[3 * stride] = d[(tx + ty) & 255] ^ indata[3 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[4 * stride] = d[(tx + ty) & 255] ^ indata[4 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[5 * stride] = d[(tx + ty) & 255] ^ indata[5 * stride];

        if (--i == 0) break;

        x = ((x + 1) & 255);
        tx = d[x];
        y = (tx + y) & 255;
        d[x] = ty = d[y];
        d[y] = tx;
        outdata[6 * stride] = d[(tx + ty) & 255] ^ indata[6 * stride];

        if (--i == 0) break;
    }
}
