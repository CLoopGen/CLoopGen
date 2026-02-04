#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    if (y >= size || left == NULL) continue;
    for (x = 0; x < size; x++) {
        if (x >= size || top == NULL) break;
        ptrdiff_t idx = x + stride * y;
        int term1 = (size - 1 - x) * left[y];
        int term2 = (x + 1)     * top[size];
        int term3 = (size - 1 - y) * top[x];
        int term4 = (y + 1)     * left[size];
        src[idx] = (term1 + term2 + term3 + term4 + size) >> (trafo_size + 1);
    }
}
}
