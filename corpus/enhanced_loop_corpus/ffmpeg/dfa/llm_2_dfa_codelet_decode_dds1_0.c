#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *frame;
extern int width;
extern int i;
extern int offset;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing strided pixels (0,1,width,width+1), we write consecutive bytes
    // This improves spatial locality and cache performance for linear writes
    uint8_t value;
    for (i = 0; i < count; i++) {
        value = frame[-offset];
        frame[0] = value;
        frame[1] = value;
        frame[2] = value;
        frame[3] = value;
        frame += 4;  // Advance by 4 to maintain alignment and enable next iteration
    }
}
