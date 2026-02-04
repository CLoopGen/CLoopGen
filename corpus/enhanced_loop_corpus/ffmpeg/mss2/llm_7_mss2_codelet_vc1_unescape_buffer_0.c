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
        temp_buffer[temp_idx] = src[i];
        if (temp_buffer[temp_idx] == 3 && i >= 2 && !temp_buffer[temp_idx-1] && !temp_buffer[temp_idx-2] && i < size - 1 && src[i+1] < 4) {
            dst[dsize++] = src[i+1];
            i++; 
            temp_idx = (temp_idx + 1) % 8;
        } else {
            dst[dsize++] = temp_buffer[temp_idx];
            temp_idx = (temp_idx + 1) % 8;
        }
    }
}
