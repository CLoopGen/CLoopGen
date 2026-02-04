#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *samples8;
extern int i;
extern int stereo;
extern int pred[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= stereo && stereo >= 0; i++) {
        if (pred[i] > 0) {
            *samples8++ = pred[i];
        }
    }
}
