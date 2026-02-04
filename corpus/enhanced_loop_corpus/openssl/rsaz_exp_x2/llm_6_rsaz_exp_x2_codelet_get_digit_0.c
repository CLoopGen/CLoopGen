#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_digit = digit;
    for (int i = 0; i < in_len; i++) {
        temp_digit <<= 8;
        temp_digit += (uint64_t)(in[i]);
    }
    digit = temp_digit;
}
