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
    uint8_t temp_buffer[8];
    int temp_idx = 0;
    for (i = 0; i < size; i++) {
        uint8_t val = src[i];
        temp_buffer[temp_idx++] = val;
        if (val == 3 && i >= 2 && src[i-1] == 0 && src[i-2] == 0 && i < size - 1 && src[i+1] < 4) {
            temp_buffer[temp_idx-1] = src[i+1];
            dst[dsize++] = temp_buffer[temp_idx-1];
            i++; 
        } else {
            dst[dsize++] = temp_buffer[temp_idx-1];
        }
        if (temp_idx >= 8) temp_idx = 0;
    }
}
