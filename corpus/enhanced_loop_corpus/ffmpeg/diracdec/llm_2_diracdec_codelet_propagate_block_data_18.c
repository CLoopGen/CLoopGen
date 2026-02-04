#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union {
    int16_t mv[2][2];
    int16_t dc[3];
};


typedef struct {
    union {
        int16_t mv[2][2];
        int16_t dc[3];
    } u;
    uint8_t ref;
} DiracBlock;

extern DiracBlock *block;
extern int stride;
extern int size;
extern int x;
extern int y;
extern DiracBlock *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with flattened indexing
    // Instead of using 2D array-like access via stride, we compute a linear offset
    // and process blocks in a more cache-friendly, consecutive manner.
    DiracBlock *base = dst + stride;
    int total_elements = size * stride;  // Full row count in destination
    int count = 0;
    for (int i = 1; i < size; i++) {
        DiracBlock *row_start = base + count;
        for (int j = 0; j < size; j++) {
            row_start[j] = *block;
        }
        count += stride;
    }
}
