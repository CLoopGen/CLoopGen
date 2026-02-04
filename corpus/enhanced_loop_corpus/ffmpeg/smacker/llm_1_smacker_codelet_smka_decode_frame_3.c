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
    if (stereo >= 0) {
        i = 0;
        for (; i <= stereo; i++)
            *samples8++ = pred[i];
    }
}
