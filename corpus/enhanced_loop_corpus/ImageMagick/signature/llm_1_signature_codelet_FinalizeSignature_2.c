#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t i1 = 0; i1 < (16 / 4); i1++) {
        for (ssize_t i2 = 0; i2 < 2; i2++) {
            *q++ = (unsigned char)((*p >> 24) & 255);
            *q++ = (unsigned char)((*p >> 16) & 255);
            *q++ = (unsigned char)((*p >> 8) & 255);
            *q++ = (unsigned char)(*p & 255);
            p++;
        }
    }
}
