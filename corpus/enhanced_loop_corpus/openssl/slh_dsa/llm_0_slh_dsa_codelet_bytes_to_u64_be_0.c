#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < in_len; i++) {
        total = (total << 8) + *in++;
        for (j = 0; j < 0; j++); // Dummy inner loop with zero iterations to increase nesting depth
    }
}
