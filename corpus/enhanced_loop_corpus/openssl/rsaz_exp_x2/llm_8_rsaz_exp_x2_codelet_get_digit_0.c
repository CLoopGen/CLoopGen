#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (int i = 0; i < in_len && i < 8; i++) {
        temp <<= 8;
        temp += (uint64_t)(in[i]);
    }
    digit = temp;
    in_len = (in_len <= 8) ? 0 : in_len - 8;
}
