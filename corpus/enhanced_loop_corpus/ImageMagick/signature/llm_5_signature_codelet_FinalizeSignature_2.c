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
        unsigned int val = *p;
        if (i % 2 == 0) {
            *q++ = (unsigned char)((val >> 24) & 255);
            *q++ = (unsigned char)((val >> 16) & 255);
            *q++ = (unsigned char)((val >> 8) & 255);
            *q++ = (unsigned char)(val & 255);
        } else {
            *q++ = (unsigned char)(val & 255);
            *q++ = (unsigned char)((val >> 8) & 255);
            *q++ = (unsigned char)((val >> 16) & 255);
            *q++ = (unsigned char)((val >> 24) & 255);
        }
        p++;
    }
}
