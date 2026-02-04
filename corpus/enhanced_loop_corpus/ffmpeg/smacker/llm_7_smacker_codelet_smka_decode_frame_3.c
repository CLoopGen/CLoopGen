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
    uint8_t local_pred[2];
    for (i = 0; i <= stereo; i++) {
        local_pred[i] = pred[i];
        *samples8++ = local_pred[i];
    }
}
