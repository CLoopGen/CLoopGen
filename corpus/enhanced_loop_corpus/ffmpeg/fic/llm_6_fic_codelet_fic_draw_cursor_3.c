#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern uint8_t planes[4][1024];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_val[4];
    for (i = 0; i < 1024; i++) {
        temp_val[0] = ptr[0];
        temp_val[1] = ptr[1];
        temp_val[2] = ptr[2];
        temp_val[3] = ptr[3];

        planes[0][i] = ((25 * temp_val[0] + 129 * temp_val[1] + 66 * temp_val[2]) / 255) + 16;
        planes[1][i] = ((-38 * temp_val[0] + 112 * temp_val[1] + -74 * temp_val[2]) / 255) + 128;
        planes[2][i] = ((-18 * temp_val[0] + 112 * temp_val[1] + -94 * temp_val[2]) / 255) + 128;
        planes[3][i] = temp_val[3];

        ptr += 4;
    }
}
