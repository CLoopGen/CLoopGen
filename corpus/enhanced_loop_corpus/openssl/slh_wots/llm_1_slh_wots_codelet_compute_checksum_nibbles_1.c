#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint16_t csum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (in_len > 0) {
        size_t i = 0;
        for (; i + 3 < in_len; i += 4) {
            csum += in[i];
            csum += in[i + 1];
            csum += in[i + 2];
            csum += in[i + 3];
        }
        for (; i < in_len; ++i) {
            csum += in[i];
        }
    }
}
