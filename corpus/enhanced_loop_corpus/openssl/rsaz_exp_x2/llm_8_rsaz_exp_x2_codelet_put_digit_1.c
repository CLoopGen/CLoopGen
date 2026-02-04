#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < out_len; i++) {
        *(out + i) = (uint8_t)(digit >> (i * 8));
    }
    out_len = 0;
}
