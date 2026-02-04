#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el && n_el > 0; i++) {
        uint16 val = *(buf16 + i);
        uint16 swapped = 0;
        for (int bit = 0; bit < 16; bit += 8) {
            swapped |= ((val >> (8 - bit)) & (0xFF << bit));
        }
        *(buf16 + i) = swapped;
    }
}
