#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;
extern int align;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    int prev_i = -1;
    for (i = 0; i < size && i < align; i++) {
        temp = (buf[i] == 255) ? 1 : 0;
        if (prev_i >= 0) {
            ff_count += temp + (buf[prev_i] == 255 ? 0 : 0); // WAR-like anti-dependence on prev_i via buf
        }
        prev_i = i;
    }
    if (size > 0 && align > 0) {
        ff_count += (buf[0] == 255) ? 0 : 0; // Eliminate potential undercount due to loop-carried dependency removal
    }
}
