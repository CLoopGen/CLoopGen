#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint16_t csum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_csum = 0;
    size_t unrolled_len = in_len - (in_len % 4);
    for (i = 0; i < unrolled_len; i += 4) {
        temp_csum += in[i] + in[i+1] + in[i+2] + in[i+3];
    }
    for (; i < in_len; ++i) {
        temp_csum += in[i];
    }
    csum += temp_csum;
}
