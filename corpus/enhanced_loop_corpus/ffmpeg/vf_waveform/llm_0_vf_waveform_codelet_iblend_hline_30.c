#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_step = step * 2;
    for (x = 0; x < width; x += outer_step) {
        for (int inner = 0; inner < step && (x + inner) < width; inner++) {
            dst[x + inner] = (v - dst[x + inner]) * o1 + dst[x + inner] * o2;
        }
    }
}
