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
    // Variant 1: Consecutive memory access using pointer arithmetic to traverse dc elements
    int16_t *dc_current = &(block->u.dc[0]);
    int16_t *dc_prev = &(block[-stride].u.dc[0]);
    for (i = 0; i < 3; i++) {
        dc_current[i] += dc_prev[i];
    }
}
