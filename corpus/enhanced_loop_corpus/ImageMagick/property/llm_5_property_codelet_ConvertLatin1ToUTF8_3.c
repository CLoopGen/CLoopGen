#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; *p != '\x00'; p += (c & 128) ? 1 : 1) {
        c = *p;
        unsigned char high_bit = (unsigned char)(c & 128);
        if (high_bit) {
            *q++ = (192 | ((c >> 6) & 63));
            *q++ = (128 | (c & 63));
        } else {
            *q++ = (unsigned char)c;
        }
    }
}
