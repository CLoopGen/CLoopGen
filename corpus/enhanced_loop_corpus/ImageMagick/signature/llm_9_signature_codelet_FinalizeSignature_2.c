#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (16 / 4); i += 2) {
    unsigned int val1 = *p++;
    unsigned int val2 = *p++;
    *q++ = (unsigned char)((val1 >> 24) & 255);
    *q++ = (unsigned char)((val1 >> 16) & 255);
    *q++ = (unsigned char)((val1 >> 8) & 255);
    *q++ = (unsigned char)(val1 & 255);
    *q++ = (unsigned char)((val2 >> 24) & 255);
    *q++ = (unsigned char)((val2 >> 16) & 255);
    *q++ = (unsigned char)((val2 >> 8) & 255);
    *q++ = (unsigned char)(val2 & 255);
}
}
