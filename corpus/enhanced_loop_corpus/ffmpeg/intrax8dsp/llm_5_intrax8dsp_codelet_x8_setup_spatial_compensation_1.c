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
    sum = 0;
    min_pix = 255;
    max_pix = 0;
    for (i = 0; i < 8; ++i) {
        c = ptr[i];
        sum += c;
        min_pix = (c < min_pix) ? c : min_pix;
        max_pix = (c > max_pix) ? c : max_pix;
    }
}
