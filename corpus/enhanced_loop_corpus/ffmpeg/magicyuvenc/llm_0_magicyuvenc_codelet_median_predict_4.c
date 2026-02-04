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
int j;
for (i = 0; i < width; i++) {
    for (j = 0; j < 1; j++) {
        dst[i] = src[i] - left;
        left = src[i];
    }
}
}
