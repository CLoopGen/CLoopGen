#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_buffer[16];
    for (i = 0; i < 16; i++) {
        local_buffer[i] = filter_ptr0[i] * 2;
    }
    for (i = 0; i < 16; i++) {
        filter_ptr0[i] = local_buffer[(15 - i)];
    }
    filter_ptr0 += 16;
}
