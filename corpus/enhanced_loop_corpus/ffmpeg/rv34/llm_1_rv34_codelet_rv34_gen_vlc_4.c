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
    if (realsize > 0) {
        i = 0;
        for (int outer = 0; outer < realsize; outer++) {
            for (int inner = 0; inner < 1; inner++) {
                cw[i] = codes[bits2[i]]++;
                i++;
            }
        }
    }
}
