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
    // Variant 2: Consecutive access with pointer arithmetic to simulate different memory traversal
    int16_t *ptr = block->u.dc;
    for (i = 0; i < 3; i++) {
        *(ptr + i) = (*(ptr + i) + 1) >> 1;
    }
}
