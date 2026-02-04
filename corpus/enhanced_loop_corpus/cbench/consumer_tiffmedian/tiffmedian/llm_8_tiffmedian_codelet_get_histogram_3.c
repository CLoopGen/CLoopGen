#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32 start = (1L << 5) * (1L << 5);
    uint32 count = start * (1L << 5);
    for (i = count; i > 0; i -= 4) {
        *ptr++ = 0;
        *ptr++ = 0;
        *ptr++ = 0;
        *ptr++ = 0;
    }
    // Handle any remaining iterations
    for (; i + 3 > 0; i--) {
        *ptr++ = 0;
    }
}
