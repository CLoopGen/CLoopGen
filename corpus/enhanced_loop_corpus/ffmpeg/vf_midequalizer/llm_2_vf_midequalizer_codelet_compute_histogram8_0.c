#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing row pointer and using linear indexing
    uint8_t *row = src;
    for (int y = 0; y < h; y++) {
        const uint8_t *end = row + w;
        for (const uint8_t *ptr = row; ptr < end; ptr++) {
            histogram[*ptr] += 1;
        }
        row += linesize;
    }
}
