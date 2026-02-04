#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int left;
extern int i;
extern int min_width;
extern  uint16_t *src16;
extern uint16_t *dst16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_prev = left;
    for (i = 0; i < min_width; i++) {
        const int temp_curr = src16[i];
        dst16[i] = temp_curr - temp_prev;
        temp_prev = temp_curr;
    }
    left = temp_prev;
}
