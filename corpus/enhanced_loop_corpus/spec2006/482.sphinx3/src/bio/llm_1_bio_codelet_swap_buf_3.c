#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int32 outer = 0; outer < n_el; outer++) {
        for (int32 inner = 0; inner < 1; inner++) {
            *(buf16 + outer) = ((255 & (*(buf16 + outer)) >> 8) | (65280 & (*(buf16 + outer)) << 8));
        }
    }
}
