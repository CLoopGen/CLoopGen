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
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[0]) = d[(tx + ty) & 255] ^ (indata[0]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[1]) = d[(tx + ty) & 255] ^ (indata[1]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[2]) = d[(tx + ty) & 255] ^ (indata[2]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[3]) = d[(tx + ty) & 255] ^ (indata[3]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[4]) = d[(tx + ty) & 255] ^ (indata[4]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[5]) = d[(tx + ty) & 255] ^ (indata[5]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    d[x] = ty = d[y];
    d[y] = tx;
    (outdata[6]) = d[(tx + ty) & 255] ^ (indata[6]);
    ;
    if (--i == 0)
        break;
}

}
