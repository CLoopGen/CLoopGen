#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int code;
extern int filled;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= code; i++) {
    dst[filled] = p;
    filled++;
    int overflow = (filled >= width);
    filled = overflow ? 0 : filled;
    dst = overflow ? dst - stride : dst;
    height = overflow ? height - 1 : height;
    if (height < 0) break;
}
}
