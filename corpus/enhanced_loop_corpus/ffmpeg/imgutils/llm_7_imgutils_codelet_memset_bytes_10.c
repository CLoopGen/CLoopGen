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
    uint8_t prev = clear[0];
    for (i = 1; same && i < clear_size; i++) {
        uint8_t curr = clear[i];
        if (curr != prev) {
            same = 0;
        }
        prev = curr;
    }
}
