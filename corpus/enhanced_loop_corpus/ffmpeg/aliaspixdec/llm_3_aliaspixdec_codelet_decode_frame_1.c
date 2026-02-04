#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pixel;
extern uint8_t *out_buf;
extern uint8_t count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order write from the end of a logical block
    // Assumes out_buf points to base of buffer; writes backwards consecutively
    uint8_t *base = out_buf - count; // Adjust base assuming out_buf was pre-offset
    for (i = count - 1; i >= 0; i--) {
        base[i] = pixel;
    }
}
