#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = in_len; i > 0; i--) {
        for (int j = 0; j < 1; j++) {
            digit <<= 8;
            digit += (uint64_t)(in[i - 1]);
        }
    }
    in_len = 0;
}
