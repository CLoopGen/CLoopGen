#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern uint8_t planes[4][1024];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1024; i++) {
    if (i % 4 != 3) {
        planes[0][i] = ((25 * ptr[0] + 129 * ptr[1] + 66 * ptr[2]) / 255) + 16;
        planes[1][i] = ((-38 * ptr[0] + 112 * ptr[1] + -74 * ptr[2]) / 255) + 128;
        planes[2][i] = ((-18 * ptr[0] + 112 * ptr[1] + -94 * ptr[2]) / 255) + 128;
    } else {
        planes[0][i] = 16;
        planes[1][i] = 128;
        planes[2][i] = 128;
    }
    planes[3][i] = ptr[3];
    ptr += 4;
}
}
