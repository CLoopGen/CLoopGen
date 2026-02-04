#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward striding)
    // This variant accesses every second byte, still checking for null terminator
    for (p = content; p[0] != '\x00' && (p + 1 == NULL || p[1] != '\x00'); p += 2) {
        // Process current and next element in a strided pattern
        length += (p[0] & 128) != 0 ? 2 : 1;
        if (p[1] != '\x00') {
            length += (p[1] & 128) != 0 ? 2 : 1;
        }
    }
}
