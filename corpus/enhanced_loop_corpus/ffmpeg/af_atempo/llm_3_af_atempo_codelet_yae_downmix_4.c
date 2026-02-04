#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reverse read order (process floats from end to start)
    uint8_t *read_ptr = src_end - ((src_end - src) % sizeof(float)); // Align to last complete float
    for (; read_ptr >= src; xdat++, read_ptr -= sizeof(float)) {
        tmp = *(const float *)read_ptr;
        *xdat = (FFTSample)tmp;
    }
    src = src_end; // Mark source as consumed to maintain logical consistency
}
