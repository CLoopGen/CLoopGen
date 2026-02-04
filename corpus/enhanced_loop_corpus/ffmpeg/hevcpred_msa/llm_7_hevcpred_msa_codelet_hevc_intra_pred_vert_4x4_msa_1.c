#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = 1;
    for (col = 1; col <= 4; col++) {
        uint32_t next = prev * col;
        prev = next;
    }
    col = prev;
}
