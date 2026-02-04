#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 16; x += 2) {
        temp[x] = 3 * src[x] + 1;
        temp[x + 1] = 5 * src[x] - 1;
        temp[x + 7 * 8] = 3 * src[x + 7 * stride] + 2;
        temp[x + 1 + 7 * 8] = 5 * src[x + 7 * stride] - 2;
    }
}
