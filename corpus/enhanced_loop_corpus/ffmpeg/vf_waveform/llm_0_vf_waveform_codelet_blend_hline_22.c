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
    for (int i = 0; i < width; i += step) {
        for (int j = 0; j < 1; ++j) {
            dst[i] = v * o1 + dst[i] * o2;
        }
    }
}
