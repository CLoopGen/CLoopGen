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
        unsigned int val = *p++;
        if ((val & 0xFF000000) != 0) {
            *q++ = (unsigned char)((val >> 24) & 255);
        } else {
            *q++ = 0;
        }
        *q++ = (unsigned char)((val >> 16) & 255);
        *q++ = (unsigned char)((val >> 8) & 255);
        *q++ = (unsigned char)(val & 255);
    }
}
