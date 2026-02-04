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
    uint8_t temp;
    for (i = 0; i < count; i++) {
        temp = frame[-offset];
        frame[0] = temp;
        frame[1] = temp;
        frame[width] = temp;
        frame[width + 1] = temp;
        frame += 2;
    }
}
