#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    consumed = 0;
    for (; consumed < in_len; consumed++) {
        uint8_t temp = *in++;
        *out++ = temp >> 4;
        *out++ = temp & 15;
    }
}
