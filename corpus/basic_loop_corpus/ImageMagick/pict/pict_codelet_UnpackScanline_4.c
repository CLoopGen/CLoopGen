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
    *q++ = (*p >> 7) & 1;
    *q++ = (*p >> 6) & 1;
    *q++ = (*p >> 5) & 1;
    *q++ = (*p >> 4) & 1;
    *q++ = (*p >> 3) & 1;
    *q++ = (*p >> 2) & 1;
    *q++ = (*p >> 1) & 1;
    *q++ = (*p & 1);
    p++;
}

}
