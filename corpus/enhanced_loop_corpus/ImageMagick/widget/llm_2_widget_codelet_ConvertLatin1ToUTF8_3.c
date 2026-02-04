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
    // Variant 1: Strided memory access with step size 2 (simulating non-unit stride)
    // We process every second byte, still ensuring bounds are respected by checking for '\x00'
    for (p = content; *p != '\x00'; p += 2) {
        c = (*p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
        // Ensure we don't overrun due to stride: check if next access would be valid
        if (p[1] == '\x00') break;
    }
}
