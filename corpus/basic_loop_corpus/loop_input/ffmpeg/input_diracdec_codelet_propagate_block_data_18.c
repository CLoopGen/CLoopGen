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
int stride;
int size;
int x;
int y;
DiracBlock *dst;

DiracBlock *global_block_storage;
DiracBlock *global_dst_base;

void init_vars() {
    size = 512;
    stride = size;
    global_block_storage = (DiracBlock*)calloc(1, sizeof(DiracBlock));
    global_dst_base = (DiracBlock*)calloc((size_t)stride * size + 1, sizeof(DiracBlock));

    if (!global_block_storage || !global_dst_base) {
        exit(1);
    }

    block = global_block_storage;
    dst = global_dst_base + 1;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}