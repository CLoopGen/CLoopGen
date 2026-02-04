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
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            // Split the computation into more steps to increase arithmetic operations
            unsigned char first = (unsigned char)(c >> 6);
            first &= 63;
            first |= 192;
            unsigned char second = (unsigned char)(c & 63);
            second |= 128;
            *q++ = first;
            *q++ = second;
        }
    }
}
