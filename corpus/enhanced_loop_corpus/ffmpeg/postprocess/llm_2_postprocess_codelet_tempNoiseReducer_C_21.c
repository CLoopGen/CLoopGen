#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
        int index = y * stride + x;
        tempBlurred[index] = src[index];
    }
}
}
