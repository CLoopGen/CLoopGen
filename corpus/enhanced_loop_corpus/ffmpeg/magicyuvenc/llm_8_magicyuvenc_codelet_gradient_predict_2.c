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
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            dst[i]     = src[i] - left;
            dst[i + 1] = src[i + 1] - src[i];
            left = src[i + 1];
        } else {
            dst[i] = src[i] - left;
            left = src[i];
        }
    }
}
