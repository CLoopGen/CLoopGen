#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0) {
        // Decreased effective nesting by collapsing into a single iteration with unrolled behavior
        // Simulating reduced loop nesting by handling all iterations in one loop with no inner loops
        do {
            *(buf++) = (unsigned char)(r & 255);
            r >>= 8;
        } while (--size);
    }
}
