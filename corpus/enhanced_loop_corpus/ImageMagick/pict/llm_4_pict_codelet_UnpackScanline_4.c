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
        unsigned char byte = *p++;
        if ((byte & 0x80) == 0) {
            *q++ = 0;
            *q++ = (byte >> 6) & 1;
            *q++ = (byte >> 5) & 1;
            *q++ = (byte >> 4) & 1;
            *q++ = (byte >> 3) & 1;
            *q++ = (byte >> 2) & 1;
            *q++ = (byte >> 1) & 1;
            *q++ = byte & 1;
        } else {
            *q++ = 1;
            *q++ = (byte >> 6) & 1;
            *q++ = (byte >> 5) & 1;
            *q++ = (byte >> 4) & 1;
            *q++ = (byte >> 3) & 1;
            *q++ = (byte >> 2) & 1;
            *q++ = (byte >> 1) & 1;
            *q++ = byte & 1;
        }
    }
}
