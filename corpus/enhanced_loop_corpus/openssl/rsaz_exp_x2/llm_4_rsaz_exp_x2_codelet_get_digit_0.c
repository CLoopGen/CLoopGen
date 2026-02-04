#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_in = in;
    int local_len = in_len;
    digit = 0; // Ensure digit starts at 0 to avoid undefined behavior
    for (int i = 0; i < local_len; i++) {
        digit <<= 8;
        digit += (uint64_t)(local_in[local_len - i - 1]);
    }
}
