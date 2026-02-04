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
    for (i = 0; i < stereo + 1 && i < 2; i++) {
        uint8_t val = pred[i] & 0x7F;
        *samples8++ = val;
        *samples8++ = val ^ 0xFF;
        pred[i] = (pred[i] + 1) % 256;
    }
}
