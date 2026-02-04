#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern unsigned char *utf8;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd byte, then check bounds)
    ptrdiff_t offset = 0;
    for (p = utf8; *(p + offset) != '\x00'; offset += 2) {
        unsigned char current = *(p + offset);
        if ((current < 32) && (current != 9) && (current != 10) && (current != 13)) {
            p = p + offset;
            break;
        }
        // Ensure we don't go past the null terminator in strides
        if (*(p + offset + 1) == '\x00') {
            p = p + offset;
            break;
        }
    }
}
