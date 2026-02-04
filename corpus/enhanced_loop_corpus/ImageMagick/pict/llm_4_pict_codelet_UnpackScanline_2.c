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
        MagickSizeType temp = *p;
        *q++ = (temp >> 4) & 255;
        if ((temp & 15) != 0) {
            *q++ = (temp & 15);
        } else {
            *q++ = 0;
        }
        p++;
    }
}
