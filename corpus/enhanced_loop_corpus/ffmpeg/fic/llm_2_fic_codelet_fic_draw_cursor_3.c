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
        int idx = i * 4;
        planes[0][i] = ((25 * ptr[idx + 0] + 129 * ptr[idx + 1] + 66 * ptr[idx + 2]) / 255) + 16;
        planes[1][i] = ((-38 * ptr[idx + 0] + 112 * ptr[idx + 1] + -74 * ptr[idx + 2]) / 255) + 128;
        planes[2][i] = ((-18 * ptr[idx + 0] + 112 * ptr[idx + 1] + -94 * ptr[idx + 2]) / 255) + 128;
        planes[3][i] = ptr[idx + 3];
    }
}
