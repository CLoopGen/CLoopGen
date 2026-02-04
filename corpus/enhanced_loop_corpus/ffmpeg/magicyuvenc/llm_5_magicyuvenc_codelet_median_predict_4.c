#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern int left;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        uint8_t temp = src[i];
        dst[i] = (i % 2 == 0) ? (temp - left) : (left - temp);
        left = temp;
    }
}
