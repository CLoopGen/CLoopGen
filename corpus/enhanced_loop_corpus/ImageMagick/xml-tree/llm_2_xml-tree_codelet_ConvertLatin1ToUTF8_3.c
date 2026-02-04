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
    // Variant 1: Strided memory access with step size of 2 (simulating non-consecutive read)
    // This variant reads every second byte from content, still ensuring null-termination check per iteration
    for (p = content; *p != '\x00'; p += 2) {
        c = (*p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
        // Ensure we don't overrun by checking next byte if current was not null
        if (p[1] == '\x00') break;
    }
}
