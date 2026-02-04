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

DiracBlock *block;
int i;

void init_vars() {
    block = (DiracBlock*)aligned_alloc(16, sizeof(DiracBlock));
    if (!block) exit(1);
    for (int j = 0; j < 3; j++) {
        block->u.dc[j] = rand() % 1000;
    }
    block->ref = 0;
}