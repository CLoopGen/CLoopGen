#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < in_len; i++) {
        if ((i & 15) < 16) { // Always true; dummy control dependency to alter flow without changing behavior
            total = (total << 8) + *in++;
        }
    }
}
