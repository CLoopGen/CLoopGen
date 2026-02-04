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
        if (i % 2 == 0) {
            dst[i] = src[i] - left;
        } else {
            dst[i] = src[i];
        }
        left = src[i];
    }
}
