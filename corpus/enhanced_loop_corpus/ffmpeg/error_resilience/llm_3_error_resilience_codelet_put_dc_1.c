#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int *linesize;
extern int dcu;
extern int dcv;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Transposed-like Access Pattern (column-major inner loop)
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int index_cb = x + y * linesize[1];
            int index_cr = x + y * linesize[2];
            dest_cb[index_cb] = dcu / 8;
            dest_cr[index_cr] = dcv / 8;
        }
    }
}
