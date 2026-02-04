#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < 9 && k < 128; j++) {
        if (x[k] > 100) continue;
        x[k] *= 10;
    }
}
