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
    uint8_t temp_load;
    for (i = 0; i < size; i++) {
        temp_load = src[i];
        if (temp_load == 3 && i >= 2 && src[i-1] == 0 && src[i-2] == 0 && i < size - 1 && src[i+1] < 4) {
            dst[dsize] = src[i+1];
            dsize++;
            i++; // Skip next element
        } else {
            dst[dsize] = temp_load;
            dsize++;
        }
    }
}
