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
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        unsigned char first = (c & 128) ? (192 | ((c >> 6) & 63)) : (unsigned char)c;
        *q++ = first;
        c &= 128;
        if (c) {
            *q++ = (unsigned char)(128 | (*p & 63));
        }
    }
}
