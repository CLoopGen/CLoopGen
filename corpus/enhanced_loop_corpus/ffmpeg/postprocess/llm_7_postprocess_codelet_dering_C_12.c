#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t src[];
extern int stride;
extern int y;
extern int min;
extern int max;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 9; y++) {
    int x;
    for (x = 1; x < 9; x++) {
        uint8_t val = src[stride * y + x];
        if (val > max)
            max = val;
        if (val < min)
            min = val;
    }
}
}
