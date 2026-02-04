#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *left_ptr = left;
    uint8_t *v_ptr = v;
    for (i = 0; i < 8 - 2; i++) {
        *(v_ptr++) = (*(left_ptr) + *(left_ptr + 1) + 1) >> 1;
        *(v_ptr++) = (*(left_ptr) + *(left_ptr + 1) * 2 + *(left_ptr + 2) + 2) >> 2;
        left_ptr++;
    }
}
