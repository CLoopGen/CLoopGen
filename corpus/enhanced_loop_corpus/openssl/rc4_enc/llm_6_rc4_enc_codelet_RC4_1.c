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
    unsigned int temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    unsigned int index = (tx + ty) & 255;
    (outdata[0]) = d[index] ^ (indata[0]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[1]) = d[index] ^ (indata[1]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[2]) = d[index] ^ (indata[2]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[3]) = d[index] ^ (indata[3]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[4]) = d[index] ^ (indata[4]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[5]) = d[index] ^ (indata[5]);
    ;
    if (--i == 0)
        break;
    x = ((x + 1) & 255);
    tx = d[x];
    y = (tx + y) & 255;
    temp = d[y];
    d[x] = ty = temp;
    d[y] = tx;
    index = (tx + ty) & 255;
    (outdata[6]) = d[index] ^ (indata[6]);
    ;
    if (--i == 0)
        break;
}
}
