#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long long MagickSizeType;

extern MagickSizeType *bytes_per_line;
extern  unsigned char *p;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)*bytes_per_line; i++) {
        unsigned char pixel = *p;
        *q++ = (pixel >> 6) & 3;
        if ((pixel & 0xC0) == 0) continue;
        *q++ = (pixel >> 4) & 3;
        if ((pixel & 0x30) == 0) continue;
        *q++ = (pixel >> 2) & 3;
        if ((pixel & 0x0C) == 0) continue;
        *q++ = pixel & 3;
        p++;
    }
}
