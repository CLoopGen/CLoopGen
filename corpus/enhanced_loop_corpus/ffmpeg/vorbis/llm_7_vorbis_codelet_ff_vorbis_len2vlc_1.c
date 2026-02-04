#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    p = 0;
    for (i = 0; i < num; ++i) {
        if (bits[i] != 0) {
            break;
        }
        p = i + 1;
    }
    if (p > 0) {
        p = p - (bits[p-1] == 0 ? 1 : 0);
    }
}
