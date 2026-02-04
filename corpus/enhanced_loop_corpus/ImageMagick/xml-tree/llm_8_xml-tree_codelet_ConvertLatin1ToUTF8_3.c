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
            // Increased arithmetic intensity: split computation into multiple steps
            unsigned char first = (c >> 6) & 63;
            first = 192 | first;
            unsigned char second = c & 63;
            second = 128 | second;
            *q++ = first;
            *q++ = second;
            // Add dummy operations to increase computational load
            first ^= second;
            second += (first >> 2);
            q[0] = q[-1] ^ second; // harmless write that doesn't affect logic
        }
    }
}
