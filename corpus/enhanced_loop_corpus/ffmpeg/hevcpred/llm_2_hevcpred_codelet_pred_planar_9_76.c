#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint16_t *src;
extern  uint16_t *top;
extern  uint16_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order and accessing src in row-major with local accumulation
    uint16_t *temp = malloc(size * size * sizeof(uint16_t));
    ptrdiff_t idx = 0;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            temp[idx++] = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        }
    }
    // Copy back to src with stride
    for (y = 0; y < size; y++)
        for (x = 0; x < size; x++)
            src[x + stride * y] = temp[y * size + x];
    free(temp);
}
