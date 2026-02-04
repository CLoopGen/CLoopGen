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
    for (i = 1; i < clear_size; i += 2) {
        if (i + 1 < clear_size) {
            if (clear[i] != clear[0] || clear[i + 1] != clear[0]) {
                same = 0;
                break;
            }
        } else {
            if (clear[i] != clear[0]) {
                same = 0;
                break;
            }
        }
    }
}
