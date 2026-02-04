#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_digit = digit;
    int local_len = in_len;
    for (int i = 0; i < local_len; i++) {
        uint8_t byte_val = in[i];
        local_digit ^= ((uint64_t)byte_val) << (i * 8 % 56); // Introduce non-linear shift and XOR to break WAW/RAW chain
    }
    digit = local_digit;
}
