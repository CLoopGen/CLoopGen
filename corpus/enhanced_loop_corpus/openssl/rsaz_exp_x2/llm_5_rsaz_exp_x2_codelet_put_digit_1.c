#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int temp_len = out_len; temp_len > 0; temp_len--) {
        uint8_t byte = (uint8_t)(digit & 255);
        if (byte != 0) {
            *out++ = byte;
        } else {
            *out++ = 1; // Replace zero byte with 1 as a simple transformation
        }
        digit >>= 8;
    }
    out_len = 0; // Ensure loop invariant is preserved
}
