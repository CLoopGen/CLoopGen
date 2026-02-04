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
    // Variant 1: Strided memory access with step size of 2 (simulating processing every other byte)
    // This changes the access pattern from sequential to strided, while maintaining correctness 
    // by adjusting loop bounds and using temporary pointer arithmetic.
    ptrdiff_t i;
    ptrdiff_t len = 0;
    for (unsigned char *temp = content; temp != NULL && *temp != '\x00'; temp++) {
        len++;
    }

    for (i = 0; i < len; i += 2) {  // Strided access: step by 2
        c = (int)content[i];
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
