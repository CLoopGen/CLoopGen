#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i, j;
    for (i = 0; i < num; ++i) {
        for (j = 0; j < 1; ++j) {
            if (bits[i] != 0) {
                p = i;
                return;
            }
        }
    }
    p = num;
}
