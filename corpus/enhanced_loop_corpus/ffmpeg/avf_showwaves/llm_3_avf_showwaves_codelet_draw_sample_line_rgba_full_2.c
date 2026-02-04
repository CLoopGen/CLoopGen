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
    // Variant 2: Strided memory access - process one color component across all rows first, then next
    int offset;
    for (int c = 0; c < 4; c++) {
        for (k = start; k < end; k++) {
            offset = k * linesize + c;
            buf[offset] = color[c];
        }
    }
}
