#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 0;
    for (i = 0; i < 8; i++) {
        temp += i;
        filter_ptr1[temp] = filter_ptr1[i] + temp;
    }
    filter_ptr1 += 8;
}
