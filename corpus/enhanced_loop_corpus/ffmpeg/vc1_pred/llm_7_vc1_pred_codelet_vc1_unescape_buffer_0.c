#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_prev, prev_curr;
    uint8_t current;
    for (i = 0; i < size; i++) {
        current = src[i];
        if (i >= 2) {
            prev_curr = src[i-1];
            prev_prev = src[i-2];
        } else {
            prev_curr = (i >= 1) ? src[i-1] : 0;
            prev_prev = (i >= 2) ? src[i-2] : 0;
        }
        if (current == 3 && i >= 2 && !prev_curr && !prev_prev && i < size - 1 && src[i+1] < 4) {
            dst[dsize++] = src[i+1];
            i++; 
        } else {
            dst[dsize++] = current;
        }
    }
}
