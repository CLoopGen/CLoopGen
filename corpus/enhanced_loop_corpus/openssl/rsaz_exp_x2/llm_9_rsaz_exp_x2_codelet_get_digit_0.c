#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in_len > 0; in_len -= 2) {
        digit <<= 16;
        digit += (uint64_t)(in[in_len - 1]) << 8;
        if (in_len >= 2) {
            digit += (uint64_t)(in[in_len - 2]);
        } else {
            break;
        }
    }
}
