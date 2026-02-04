#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int32_t *block;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int row = i / 8;
        int col = i % 8;
        dest[col + row * linesize] += block[col + row * 8];
        if (col == 7) {
            dest += linesize;
            block += 8;
        }
    }
}
