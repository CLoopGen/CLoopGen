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
    // Variant 2: Strided memory access with vertical emphasis
    // Access pixels in a column-wise (strided) fashion across multiple rows
    // Simulates processing block corners with vertical stride, increasing cache line usage
    int stride = width * 2;  // Assume larger stride for vertical spacing
    uint8_t value;
    for (i = 0; i < count; i++) {
        value = frame[-offset];
        frame[0]             = value;
        frame[width]         = value;
        frame[stride]        = value;
        frame[stride + width] = value;
        frame += 1;  // Move forward by one pixel each iteration (horizontal sliding)
    }
}
