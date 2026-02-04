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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided access pattern — treat the dc array as part of a larger structure and use scaled indexing
    // Simulate a strided access by stepping through bytes and casting appropriately
    ptrdiff_t offset = (char*)(&block->u.dc[1]) - (char*)(&block->u.dc[0]); // byte stride between dc elements
    int16_t *base_curr = &block->u.dc[0];
    int16_t *base_prev = &block[-1 - stride].u.dc[0];
    for (i = 0; i < 3; i++) {
        *(int16_t*)((char*)base_curr + i * offset) += *(int16_t*)((char*)base_prev + i * offset);
    }
}
