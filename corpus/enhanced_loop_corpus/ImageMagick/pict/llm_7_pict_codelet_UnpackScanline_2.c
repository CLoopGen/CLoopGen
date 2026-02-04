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
    unsigned char *local_p = p;
    unsigned char *local_q = q;
    ssize_t count = (ssize_t)*bytes_per_line;

    for (i = 0; i < count; i++) {
        unsigned char val = *local_p++;
        local_q[0] = (val >> 4) & 255;
        local_q[1] = val & 15;
        local_q += 2;
    }

    q = local_q;
    p = local_p;
}
