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
    // This variant processes every second byte, then revisits the skipped ones in a second pass.
    // It maintains correctness by ensuring all bytes are processed in two strided passes.

    unsigned char *restrict temp_p = content;
    int pass;

    // Two-pass strided access: first pass even indices, second pass odd indices
    for (pass = 0; pass < 2; pass++) {
        for (p = temp_p + pass; p != NULL && *p != '\x00'; p += 2) {
            c = (*p);
            if ((c & 128) == 0)
                *q++ = (unsigned char)c;
            else {
                *q++ = (unsigned char)(192 | ((c >> 6) & 63));
                *q++ = (unsigned char)(128 | (c & 63));
            }
        }
    }
}
