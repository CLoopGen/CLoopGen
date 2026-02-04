#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < 16; i++)
            out[i] = in[15 - i];
}
