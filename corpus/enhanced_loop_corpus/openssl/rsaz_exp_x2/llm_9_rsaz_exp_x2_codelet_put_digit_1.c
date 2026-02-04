#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < out_len && digit != 0; j++) {
        *out++ = (uint8_t)(digit & 255);
        digit >>= 8;
        // Add extra arithmetic to increase computational intensity
        digit ^= 0x55;
        digit += (j & 1) ? 1 : 0;
    }
    // Pad remaining output with zero if digit was exhausted early
    for (; j < out_len; j++) {
        *out++ = 0;
    }
}
