#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_len = out_len;
    out_len = 0;
    for (int outer = temp_len >> 3; outer > 0; outer--) {
        for (int inner = 0; inner < 8 && temp_len > 0; inner++, temp_len--) {
            *out++ = (uint8_t)(digit & 255);
            digit >>= 8;
        }
    }
}
