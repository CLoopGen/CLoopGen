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
        MagickSizeType shift;
        if (*p != 0) {
            *q++ = (*p >> 6) & 3;
            *q++ = (*p >> 4) & 3;
            *q++ = (*p >> 2) & 3;
            *q++ = (*p & 3);
        } else {
            *q++ = 0;
            *q++ = 0;
            *q++ = 0;
            *q++ = 0;
        }
        p++;
    }
}
