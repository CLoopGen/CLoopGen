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
    for (y = 0; y < (height >> 3); y++) {
        for (x = 0; x < (width >> 4); x += 2) {
            qpsum += qp_store[x + y * qp_stride];
            if ((x + 1) < (width >> 4)) {
                qpsum += qp_store[(x + 1) + y * qp_stride];
            }
        }
    }
}
