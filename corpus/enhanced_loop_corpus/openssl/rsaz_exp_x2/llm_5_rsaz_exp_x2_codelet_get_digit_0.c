#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    digit = 0;
    uint8_t temp;
    for (int i = in_len; i > 0; i--) {
        temp = in[i - 1];
        if (temp == 0) continue; // Introduce control dependency: skip further processing if byte is zero
        digit <<= 8;
        digit += (uint64_t)temp;
    }
}
