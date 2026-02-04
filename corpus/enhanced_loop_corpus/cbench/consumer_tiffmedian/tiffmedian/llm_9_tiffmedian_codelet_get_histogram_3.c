#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32 trip_count = (1L << 5) * (1L << 5) * (1L << 5);
    uint32 stride = 8;
    for (i = 0; i < trip_count; i++) {
        uint32 j;
        uint32 limit = (trip_count - i) < stride ? (trip_count - i) : stride;
        for (j = 0; j < limit; j++) {
            *ptr++ = 0;
        }
        i += stride - 1; // Compensate for outer loop increment
    }
}
