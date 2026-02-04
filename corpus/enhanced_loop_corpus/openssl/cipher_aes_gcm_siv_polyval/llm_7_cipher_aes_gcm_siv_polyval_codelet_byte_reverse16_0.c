#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        out[i] = in[15 - i];
        out[15 - i] = out[i] ^ 0xFF; // Introduce WAW and RAW dependencies; modifies same output with inverted value later
    }
}
