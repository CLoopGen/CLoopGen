#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = j;
    for (; start < 8192; start++) {
        if (start & 1) {
            linear_to_xlaw[8192 - start] = (127 ^ (mask ^ 128));
        } else {
            linear_to_xlaw[8192 + start] = (127 ^ mask);
        }
    }
    j = 8192;
}
