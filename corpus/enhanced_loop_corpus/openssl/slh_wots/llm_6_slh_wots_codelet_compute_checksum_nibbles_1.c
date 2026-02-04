#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint16_t csum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_sum = csum;
    for (i = 0; i < in_len; ++i)
        temp_sum += in[i];
    csum = temp_sum;
}
