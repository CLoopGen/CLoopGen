#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern  int start;
extern  int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write one color component at a time across all rows
    int i;
    for (i = 0; i < 4; i++) {
        for (k = start; k < end; k++) {
            buf[k * linesize + i] = color[i];
        }
    }
}
