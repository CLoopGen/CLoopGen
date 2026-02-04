#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write one color component across all rows first, then next
    for (int col = 0; col < 4; col++) {
        uint8_t val = color[col];
        for (k = start + 1; k < end; k++) {
            buf[k * linesize + col] = val;
        }
    }
}
