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
    for (i = 0; i < ((48 + 7) / 8); i += 2) {
        uint8_t a1 = buf[(pos - i) & (16 - 1)];
        uint8_t b1 = buf[(pos - (((48 + 7) / 8) * 2 - 1) + i) & (16 - 1)];
        sum += ctables[i][a1] + ctables[i][b1];
        if (i + 1 < ((48 + 7) / 8)) {
            uint8_t a2 = buf[(pos - (i + 1)) & (16 - 1)];
            uint8_t b2 = buf[(pos - (((48 + 7) / 8) * 2 - 1) + (i + 1)) & (16 - 1)];
            sum += ctables[i + 1][a2] + ctables[i + 1][b2];
        }
    }
}
