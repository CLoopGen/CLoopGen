#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (consumed = 0; consumed < in_len; consumed++) {
        uint8_t val = *in++;
        if ((val & 15) != 0) {
            *out++ = (val >> 4);
            *out++ = (val & 15);
        } else {
            *out++ = (val >> 4);
        }
    }
}
