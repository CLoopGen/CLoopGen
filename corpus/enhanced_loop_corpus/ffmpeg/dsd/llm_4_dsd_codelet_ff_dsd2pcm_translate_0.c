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
    for (i = 0; i < ((48 + 7) / 8); i++) {
        if (i % 2 == 0) {
            uint8_t a = buf[(pos - i) & (16 - 1)];
            sum += ctables[i][a];
        } else {
            uint8_t b = buf[(pos - (((48 + 7) / 8) * 2 - 1) + i) & (16 - 1)];
            sum += ctables[i][b];
        }
    }
}
