#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (simulating non-unit stride)
    // This variant processes every second byte, still ensuring bounds are respected by checking for '\x00'
    ptrdiff_t stride = 2;
    unsigned char *end = content;
    while (*end != '\x00') end++;  // Find null terminator
    for (p = content; p < end; p += stride) {
        c = (*p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
