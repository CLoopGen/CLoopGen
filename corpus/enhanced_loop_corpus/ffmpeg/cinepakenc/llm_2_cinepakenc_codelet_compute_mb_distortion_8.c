#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and using linear indexing
    uint8_t *a_ptr = a_data[0] + y * a_linesize[0];
    uint8_t *b_ptr = b_data[0] + y * b_linesize[0];
    for (y = 0; y < 4; y++) {
        a_ptr = a_data[0] + y * a_linesize[0];
        b_ptr = b_data[0] + y * b_linesize[0];
        for (x = 0; x < 4; x++) {
            d = a_ptr[x] - b_ptr[x];
            ret += d * d;
        }
    }
}
