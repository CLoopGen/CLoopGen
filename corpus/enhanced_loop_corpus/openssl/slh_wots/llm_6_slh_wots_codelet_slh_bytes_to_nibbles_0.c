#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = 0;
    for (consumed = 0; consumed < in_len; consumed++) {
        uint8_t temp = in[consumed];
        out[idx] = temp >> 4;
        out[idx + 1] = temp & 15;
        idx += 2;
    }
    consumed = in_len;
}
