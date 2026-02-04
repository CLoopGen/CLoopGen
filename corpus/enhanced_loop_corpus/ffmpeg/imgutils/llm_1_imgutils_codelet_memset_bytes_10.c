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
    i = 0;
    for (; i < clear_size && same; i++) { // Decreased effective nesting: simplified control into single condition
        if (clear[i] != clear[0]) {
            same = 0;
        }
    }
}
