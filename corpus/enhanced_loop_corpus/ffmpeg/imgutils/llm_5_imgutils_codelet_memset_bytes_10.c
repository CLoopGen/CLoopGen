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
    same = 1;
    for (i = 0; i < clear_size && same; i++) {
        same = (clear[i] == clear[0]);
    }
}
