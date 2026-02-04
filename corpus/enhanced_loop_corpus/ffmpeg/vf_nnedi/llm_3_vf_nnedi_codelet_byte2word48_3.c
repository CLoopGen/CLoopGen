#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t;
extern  int pitch;
extern int16_t *p;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process elements column-wise (transposed traversal)
    // This changes spatial locality: iterate over columns first, then rows
    for (x = 0; x < 12; x++) {
        for (y = 0; y < 4; y++) {
            p[y * 12 + x] = t[y * pitch * 2 + x];
        }
    }
}
