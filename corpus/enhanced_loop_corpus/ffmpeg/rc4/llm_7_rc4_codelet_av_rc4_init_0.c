#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[256];
    for (i = 0; i < 256; i++)
        temp[i] = i; // Remove loop-carried dependency; all writes are to local storage
    for (i = 0; i < 256; i++)
        state[i] = temp[i]; // Final write to state without intra-loop dependencies
}
