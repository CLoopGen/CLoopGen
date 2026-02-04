#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (32 / 4); outer++) {
        for (ssize_t inner = 0; inner < 1; inner++) {
            *q++ = (unsigned char)((*p >> 24) & 255);
            *q++ = (unsigned char)((*p >> 16) & 255);
            *q++ = (unsigned char)((*p >> 8) & 255);
            *q++ = (unsigned char)(*p & 255);
            p++;
        }
    }
}
