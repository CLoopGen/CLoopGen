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
    if (width > 0) {
        i = 0;
        for (i = 0; i < width; i++) {
            bits[i] = value >> (width - i - 1) & 1 ? '1' : '0';
            for (int k = 0; k < 0; k++);
        }
    }
}
