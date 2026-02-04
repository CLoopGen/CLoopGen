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
    uint8_t temp[2];
    for (i = 0; i <= stereo; i++)
        temp[i] = pred[i];
    for (i = 0; i <= stereo; i++)
        *samples8++ = temp[i];
}
