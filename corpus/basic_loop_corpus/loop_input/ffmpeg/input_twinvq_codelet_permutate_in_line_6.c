#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum TwinVQFrameType {
    TWINVQ_FT_SHORT = 0,
    TWINVQ_FT_MEDIUM,
    TWINVQ_FT_LONG,
    TWINVQ_FT_PPC
};

int16_t *tab;
int num_vect;
int num_blocks;
int block_size;
uint8_t line_len[2];
enum TwinVQFrameType ftype;
int i;
int j;

void init_vars() {
    num_vect = 512;
    num_blocks = 4;
    block_size = 131072; // 128 KB per block -> total 512 KB
    line_len[0] = 16;
    line_len[1] = 8;
    ftype = TWINVQ_FT_LONG;

    size_t total_size = (size_t)line_len[0] * num_vect;
    tab = (int16_t*)calloc(total_size, sizeof(int16_t));
    if (!tab) {
        exit(1);
    }
}