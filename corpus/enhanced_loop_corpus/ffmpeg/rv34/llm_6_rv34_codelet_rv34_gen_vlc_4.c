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
    int temp;
    for (i = 0; i < realsize; i++) {
        temp = bits2[i];
        cw[i] = codes[temp];
        codes[temp] = codes[temp] + 1;
    }
}
