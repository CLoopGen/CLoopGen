#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; consumed < in_len; i++, consumed++) {
        uint8_t val = in[consumed];
        out[i * 2] = val >> 4;
        out[i * 2 + 1] = val & 15;
    }
}
