#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            filter_ptr1 += 4;
        }
        filter_ptr1 += 4;
    }
}
