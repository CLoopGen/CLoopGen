#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (out_len <= 0) return;
    for (int i = 0; i < out_len; i++) {
        *out++ = (uint8_t)(digit & 255);
        digit >>= 8;
    }
}
