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
    for (int j = 0; j < count; j++) {
        for (i = 0; i < 1; i++) {
            frame[0] = frame[1] = frame[width] = frame[width + 1] = frame[-offset];
            frame += 2;
        }
    }
}
