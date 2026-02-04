#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *top;
extern uint8_t *left;
extern int x;
extern int ih;
extern int iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 4; x += 2) {
        for (int inner = 0; inner < 2; inner++) {
            int idx = x + inner;
            ih += (idx + 1) * (top[5 + idx] - top[3 - idx]);
            iv += (idx + 1) * (left[5 + idx] - left[3 - idx]);
        }
    }
}
