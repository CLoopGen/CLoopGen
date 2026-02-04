#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 0;
    for (int i = 0; i < stride * height; i++) {
        temp = !planep[i];
        planep[i] = temp;
    }
}
