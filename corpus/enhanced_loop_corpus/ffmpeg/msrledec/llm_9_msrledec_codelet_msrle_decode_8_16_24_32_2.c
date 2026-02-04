#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint8_t pix[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < p1; i++) {
        for (j = 0; j < 3; j++) {
            *output++ = pix[j];
        }
    }
}
