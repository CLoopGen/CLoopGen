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
    unsigned char *temp_p = p;
    unsigned char *temp_q = q;
    ssize_t n = (ssize_t)*bytes_per_line;
    for (i = 0; i < n; i += 4) { // Process 4 elements per iteration (consecutive block access)
        ssize_t limit = i + 4 <= n ? i + 4 : n;
        for (ssize_t j = i; j < limit; j++) {
            *temp_q++ = (*temp_p >> 4) & 255;
            *temp_q++ = (*temp_p & 15);
            temp_p++;
        }
    }
    p = temp_p;
    q = temp_q;
}
