#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *clear;
extern size_t clear_size;
extern int same;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_same = 1;
    uint8_t first_val = clear[0];
    for (i = 1; i < clear_size; i++) {
        temp_same &= (clear[i] == first_val);
    }
    same = temp_same;
}
