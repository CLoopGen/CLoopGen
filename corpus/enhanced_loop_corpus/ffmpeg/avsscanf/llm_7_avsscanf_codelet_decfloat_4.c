#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = 1;
    for (; j < 9; j++) {
        uint32_t current = x[k] * prev;
        x[k] = current;
        prev = current;
    }
}
