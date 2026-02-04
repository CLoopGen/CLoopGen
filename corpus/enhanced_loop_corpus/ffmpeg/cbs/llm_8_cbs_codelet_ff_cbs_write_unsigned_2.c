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
    int j;
    for (i = 0; i < width * 2; i += 2) {
        int shift_amount = width - i - 1;
        if (shift_amount >= 0) {
            bits[i] = ((value >> shift_amount) & 1) ? '1' : '0';
            bits[i + 1] = (i + 1 < width) ? (((value >> (shift_amount - 1)) & 1) ? '1' : '0') : '\0';
        } else {
            bits[i] = '\0';
            if (i + 1 < 33) bits[i + 1] = '\0';
        }
    }
    if (width % 2 == 1 && width < 33)
        bits[width - 1] = ((value >> 0) & 1) ? '1' : '0';
}
