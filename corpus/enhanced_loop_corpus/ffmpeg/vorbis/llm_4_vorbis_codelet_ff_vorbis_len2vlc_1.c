#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    p = 0;
    if (num == 0) return;
    for (; p < num; ++p) {
        if (bits[p] != 0) break;
    }
}
