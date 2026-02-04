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
    for (i = 0; i < min_width; i++) {
        const int temp = src16[i];
        dst16[i] = (i % 2 == 0) ? (temp - left) : temp;
        left = temp;
    }
}
