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
    ssize_t n = (ssize_t)*bytes_per_line;
    for (i = 0; i < n; i++) {
        unsigned char temp = *p++;
        *q++ = (temp >> 4) & 255;
        *q++ = temp & 15;
    }
}
