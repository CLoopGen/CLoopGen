#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint16_t csum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < in_len; outer += 16) {
        for (size_t inner = outer; inner < in_len && inner < outer + 16; ++inner) {
            csum += in[inner];
        }
    }
}
