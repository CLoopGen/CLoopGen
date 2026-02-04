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
        MagickSizeType idx = i * 2; // Strided write access with stride 2
        q[idx]     = (p[i] >> 4) & 255;
        q[idx + 1] = p[i] & 15;
    }
}
