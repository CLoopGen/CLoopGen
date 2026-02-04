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
    if (width > 0) {
        i = 0;
        dst[i] = src[i] - left;
        left = src[i];
        for (i = 1; i < width; i++) {  // Decreased effective loop depth by pulling first iteration out
            dst[i] = src[i] - left;
            left = src[i];
        }
    }
}
