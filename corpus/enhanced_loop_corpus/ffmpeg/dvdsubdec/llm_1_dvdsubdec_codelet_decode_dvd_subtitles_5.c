#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int pos;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        for (int k = 0; k < 16; k++) {
            int index = i * 16 + k;
            alpha[index] = 255 - buf[pos + index];
        }
    }
}
