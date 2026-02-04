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
    if (clear_size == 0) {
        same = 1;
        return;
    }
    same = 1;
    for (i = 1; i < clear_size; i++) {
        for (int j = 0; j < 1; j++) { // Increased nesting depth: added inner loop with single iteration
            if (clear[i] != clear[0]) {
                same = 0;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
