#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el; i++) {
        if (i % 2 == 0) {
            *(buf16 + i) = ((255 & (*(buf16 + i)) >> 8) | (65280 & (*(buf16 + i)) << 8));
        } else {
            continue;
        }
    }
}
