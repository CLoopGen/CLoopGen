#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el * 2; i += 2) {
        if (i + 1 < n_el) {
            uint16 temp1 = *(buf16 + i);
            uint16 temp2 = *(buf16 + i + 1);
            *(buf16 + i) = ((255 & temp1 >> 8) | (65280 & temp1 << 8));
            *(buf16 + i + 1) = ((255 & temp2 >> 8) | (65280 & temp2 << 8));
        } else if (i < n_el) {
            *(buf16 + i) = ((255 & (*(buf16 + i)) >> 8) | (65280 & (*(buf16 + i)) << 8));
        }
    }
}
