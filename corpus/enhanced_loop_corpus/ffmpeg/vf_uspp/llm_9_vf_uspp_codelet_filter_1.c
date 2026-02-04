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
    int y, x;
    for (y = 0; y < (height >> 4); y += 2) {
        for (x = 0; x < (width >> 5); x++) {
            qpsum += qp_store[x*2 + y * qp_stride];
            qpsum += qp_store[x*2 + (y+1) * qp_stride];
        }
    }
}
