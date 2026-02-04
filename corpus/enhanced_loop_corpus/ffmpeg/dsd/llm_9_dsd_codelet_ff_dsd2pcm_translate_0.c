#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ctables[6][256];
extern uint8_t buf[16];
extern unsigned int pos;
extern unsigned int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((48 + 7) / 8) * 3; i++) {
        uint8_t a = buf[(pos - (i % ((48 + 7) / 8))) & (16 - 1)];
        uint8_t b = buf[(pos - (((48 + 7) / 8) * 2 - 1) + (i % ((48 + 7) / 8))) & (16 - 1)];
        sum += ctables[i % ((48 + 7) / 8)][a] * ctables[i % ((48 + 7) / 8)][b];
    }
}
