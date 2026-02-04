#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[33] = {0};
    for (i = 0; i < width; i++) {
        int shifted_index = width - i - 1;
        uint32_t extracted_bit = (value >> shifted_index) & 1;
        temp[i] = extracted_bit ? '1' : '0';
    }
    for (i = 0; i < width; i++) {
        bits[i] = temp[i];
    }
}
