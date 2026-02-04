#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp;
    for (; j < 9; j++) {
        temp = x[k] * 10;
        x[k] = temp;
    }
}
