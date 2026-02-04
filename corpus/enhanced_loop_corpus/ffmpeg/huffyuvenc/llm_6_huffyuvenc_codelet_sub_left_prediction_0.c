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
    uint8_t temp_store;
    for (i = 0; i < min_width; i++) {
        temp_store = src[i];
        dst[i] = temp_store - left;
        left = temp_store;
    }
}
