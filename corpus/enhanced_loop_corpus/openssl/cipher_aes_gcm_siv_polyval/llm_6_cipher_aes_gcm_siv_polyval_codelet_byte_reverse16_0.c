#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[16];
    for (i = 0; i < 16; i++)
        temp[i] = in[15 - i];
    for (i = 0; i < 16; i++)
        out[i] = temp[i];
}
