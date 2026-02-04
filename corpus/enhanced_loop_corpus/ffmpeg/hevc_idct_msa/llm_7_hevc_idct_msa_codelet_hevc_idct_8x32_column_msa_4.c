#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_cache[8];
    for (i = 0; i < 8; i++) {
        local_cache[i] = filter_ptr1[i] * 2;
    }
    for (i = 0; i < 8; i++) {
        filter_ptr1[i] = local_cache[(7 - i)]; 
    }
    filter_ptr1 += 8;
}
