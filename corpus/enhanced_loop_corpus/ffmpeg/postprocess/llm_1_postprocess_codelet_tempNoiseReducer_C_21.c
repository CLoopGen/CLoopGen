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
    int y_inner, y_outer;
    for (y_outer = 0; y_outer < 4; y_outer++) {
        for (y_inner = 0; y_inner < 2; y_inner++) {
            int y = y_outer * 2 + y_inner;
            int x;
            for (x = 0; x < 8; x++) {
                tempBlurred[x + y * stride] = src[x + y * stride];
            }
        }
    }
}
