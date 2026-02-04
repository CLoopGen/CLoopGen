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
    uint8_t temp;
    for (i = 0; i < size; i++) {
        if (i >= 2 && src[i] == 3 && !src[i-1] && !src[i-2] && i < size - 1 && src[i+1] < 4) {
            temp = src[i+1];
            dst[dsize] = temp;
            dsize++;
            i++; 
            src++; 
        } else {
            dst[dsize] = src[i];
            dsize++;
        }
    }
}
