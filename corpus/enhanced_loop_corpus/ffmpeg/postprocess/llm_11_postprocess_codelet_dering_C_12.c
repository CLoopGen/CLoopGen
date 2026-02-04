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
    uint8_t temp_min = min;
    uint8_t temp_max = max;
    for (y = 1; y < 9; y++) {
        int x;
        p = src + stride * y + 1;
        for (x = 1; x < 9; x++) {
            uint8_t val = p[x];
            if (val > temp_max)
                temp_max = val;
            if (val < temp_min)
                temp_min = val;
        }
    }
    min = temp_min;
    max = temp_max;
}
