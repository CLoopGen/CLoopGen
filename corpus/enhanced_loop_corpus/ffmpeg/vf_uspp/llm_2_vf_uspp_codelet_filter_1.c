#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern uint8_t *qp_store;
extern int qp_stride;
extern int x;
extern int y;
extern int qpsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing row pointers and accessing qp_store in a more cache-friendly linear fashion
    for (y = 0; y < (height >> 4); y++) {
        uint8_t *row = &qp_store[y * qp_stride];
        for (x = 0; x < (width >> 4); x++) {
            qpsum += row[x];
        }
    }
}
