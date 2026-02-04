#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_i = p;
    for (i = p; (temp_i < num) && (bits[temp_i] == 0); ++temp_i) {
        i = temp_i + 1;
    }
    if (temp_i >= num || bits[temp_i] != 0) {
        i = temp_i;
    }
}
