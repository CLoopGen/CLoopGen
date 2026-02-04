#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 16; i++)
    out[i] = in[15 - i];

}
