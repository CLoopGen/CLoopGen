#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (32 / 4); i++) {
    unsigned int temp = *p++;
    *q++ = (unsigned char)((temp >> 24) & 255);
    *q++ = (unsigned char)((temp >> 16) & 255);
    *q++ = (unsigned char)((temp >> 8) & 255);
    *q++ = (unsigned char)(temp & 255);
}
}
