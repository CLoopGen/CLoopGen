#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int codes[17];
extern uint16_t cw[1296];
extern uint8_t bits2[1296];
extern int realsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < realsize; i++) {
        int idx = bits2[i];
        if (idx != 0) {
            cw[i] = codes[idx]++;
        } else {
            cw[i] = 0;
        }
    }
}
