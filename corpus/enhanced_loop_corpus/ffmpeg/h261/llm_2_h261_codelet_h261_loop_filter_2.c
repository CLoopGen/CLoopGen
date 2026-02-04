#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int xy;
extern int yz;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via temporary row buffer
    uint8_t row[8];
    for (y = 0; y < 8; y++) {
        // Load a transformed segment of 'temp' into a local row buffer (consecutive access)
        for (x = 0; x < 8; x++) {
            if (x == 0) {
                row[x] = (temp[y * 8 + x] + 2) >> 2;
            } else if (x == 7) {
                row[x] = (temp[y * 8 + x] + 2) >> 2;
            } else {
                row[x] = (temp[y * 8 + x - 1] + 2 * temp[y * 8 + x] + temp[y * 8 + x + 1] + 8) >> 4;
            }
        }
        // Store entire row consecutively into strided output
        for (x = 0; x < 8; x++) {
            src[y * stride + x] = row[x];
        }
    }
}
