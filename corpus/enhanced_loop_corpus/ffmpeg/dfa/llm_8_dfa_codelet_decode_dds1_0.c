#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *frame;
extern int width;
extern int i;
extern int offset;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count * 2; i += 2) {
        uint8_t val = frame[-offset];
        frame[0] = val;
        frame[1] = val;
        frame[width] = val;
        frame[width + 1] = val;
        frame += 2;
    }
}
