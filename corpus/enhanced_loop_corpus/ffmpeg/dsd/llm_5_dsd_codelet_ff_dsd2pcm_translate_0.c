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
        uint8_t index_a = (pos - i) & (16 - 1);
        uint8_t index_b = (pos - (((48 + 7) / 8) * 2 - 1) + i) & (16 - 1);
        if (index_a != index_b) {
            sum += ctables[i][index_a] + ctables[i][index_b];
        } else {
            sum += ctables[i][index_a];
        }
    }
}
