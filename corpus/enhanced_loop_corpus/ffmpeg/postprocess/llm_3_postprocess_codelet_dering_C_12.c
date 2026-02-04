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
    int y;
    for (y = 1; y < 9; y++) {
        int x;
        p = src + stride * y;
        x = 1;
        for (; x < 9; x++) {
            p++;
            if (*p > max)
                max = *p;
            if (*p < min)
                min = *p;
        }
    }
}
