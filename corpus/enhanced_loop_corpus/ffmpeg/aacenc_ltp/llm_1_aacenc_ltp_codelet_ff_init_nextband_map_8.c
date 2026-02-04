#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_g;
for (outer_g = 0; outer_g < 128; outer_g += 16) {
    int inner_g;
    for (inner_g = outer_g; inner_g < outer_g + 16 && inner_g < 128; inner_g++)
        nextband[inner_g] = inner_g;
}
}
