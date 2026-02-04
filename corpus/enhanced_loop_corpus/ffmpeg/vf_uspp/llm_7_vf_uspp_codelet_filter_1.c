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
    qpsum = 0;
    for (y = 0; y < (height >> 4); y++) {
        for (x = 0; x < (width >> 4); x++) {
            int index = x + y * qp_stride;
            qpsum = qpsum + qp_store[index] + (qp_store[index] >> 1); // Introduces WAW on qpsum and uses same load twice (RAW dependency)
        }
    }
}
