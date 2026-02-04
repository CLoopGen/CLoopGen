#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t i;
    for (i = 0; i < 4; i++) {
        filter_ptr1[0] = (int16_t)((filter_ptr1[0] * 3) / 2);
        filter_ptr1[1] = (int16_t)((filter_ptr1[1] * 3) / 2);
        filter_ptr1[2] = (int16_t)((filter_ptr1[2] * 3) / 2);
        filter_ptr1[3] = (int16_t)((filter_ptr1[3] * 3) / 2);
        filter_ptr1 += 2;
    }
}
