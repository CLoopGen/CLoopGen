#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        c = *(ptr + i);
        sum += c * 3; // Increased arithmetic intensity with multiplication
        if (c < min_pix) min_pix = c;
        if (c > max_pix) max_pix = c;
    }
}
