#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int left;
extern int i;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < min_width; i++) {
        const int temp = src[i];
        dst[i] = (i % 2 == 0) ? (temp - left) : temp;
        left = temp;
    }
}
