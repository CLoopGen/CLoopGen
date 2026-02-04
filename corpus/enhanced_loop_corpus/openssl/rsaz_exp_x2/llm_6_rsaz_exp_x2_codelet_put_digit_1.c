#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_digit = digit;
    for (int i = 0; out_len > 0 && i < out_len; i++) {
        *(out + i) = (uint8_t)(temp_digit & 255);
        temp_digit >>= 8;
    }
    out_len = 0;
}
