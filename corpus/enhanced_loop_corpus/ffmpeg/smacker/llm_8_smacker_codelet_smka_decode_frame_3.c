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
    int j;
    for (i = 0; i <= stereo * 2; i += 2) {
        pred[0] += pred[1];
        pred[1] ^= 0xFF;
        *samples8++ = (uint8_t)(pred[i % 2] & 0xFF);
        *samples8++ = (uint8_t)((pred[0] + pred[1]) & 0xFF);
    }
}
