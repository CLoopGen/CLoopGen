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
    ssize_t j;
    for (i = 0; i < (ssize_t)*bytes_per_line; i++) {
        unsigned char val = *p++;
        for (j = 0; j < 4; j++) {
            *q++ = (val >> (6 - 2*j)) & 3;
        }
    }
}
