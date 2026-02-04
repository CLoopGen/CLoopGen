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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element in a larger conceptual array, using modulo to stay within bounds)
    int indices[3] = {0, 2, 1}; // Custom access pattern: strided and reordered
    for (i = 0; i < 3; i++) {
        int idx = indices[i];
        block->u.dc[idx] = (block->u.dc[idx] + 1) >> 1;
    }
}
