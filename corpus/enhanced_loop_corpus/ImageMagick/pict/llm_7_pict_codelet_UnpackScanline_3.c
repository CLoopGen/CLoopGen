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
    unsigned char temp[4];
    for (i = 0; i < n; i++) {
        temp[0] = (*p >> 6) & 3;
        temp[1] = (*p >> 4) & 3;
        temp[2] = (*p >> 2) & 3;
        temp[3] = (*p & 3);
        p++;
        *q++ = temp[0];
        *q++ = temp[1];
        *q++ = temp[2];
        *q++ = temp[3];
    }
}
