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
    // Variant 2: Strided memory access — write every second byte (simulating interleaving)
    uint8_t *ptr = samples8;
    for (i = 0; i <= stereo; i++) {
        ptr[i * 2] = pred[i]; // Write with stride of 2
    }
    samples8 += (stereo + 1) * 2; // Advance pointer accordingly
}
