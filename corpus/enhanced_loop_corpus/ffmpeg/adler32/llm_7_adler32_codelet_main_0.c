#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t data[7001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_val = 0;
    for (i = 0; i < 7001; i++) {
        uint8_t computed = ((i * i) >> 3) + 123 * i;
        data[i] = computed + prev_val;
        prev_val = computed;
    }
}
