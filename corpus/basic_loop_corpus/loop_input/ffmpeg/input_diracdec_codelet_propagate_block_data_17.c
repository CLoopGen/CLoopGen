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
int size;
int x;
DiracBlock *dst;

void init_vars() {
    size = 65536;
    block = (DiracBlock*)malloc(sizeof(DiracBlock));
    dst = (DiracBlock*)malloc(size * sizeof(DiracBlock));

    block->u.mv[0][0] = 1;
    block->u.mv[0][1] = 2;
    block->u.mv[1][0] = 3;
    block->u.mv[1][1] = 4;
    block->ref = 5;

    for (int i = 0; i < size; i++) {
        dst[i].u.dc[0] = 0;
        dst[i].u.dc[1] = 0;
        dst[i].u.dc[2] = 0;
        dst[i].ref = 0;
    }

    x = 0;
}