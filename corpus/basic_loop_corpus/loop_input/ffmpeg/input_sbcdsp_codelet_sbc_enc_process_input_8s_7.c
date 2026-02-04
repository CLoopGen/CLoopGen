#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

int position;
uint8_t *pcm;
int16_t X[2][328];
int nchannels;
int c;

void init_vars() {
    nchannels = 2;
    position = 0;

    size_t pcm_size = 14 * nchannels + 2 * (nchannels - 1) + 2;
    pcm = aligned_alloc(16, pcm_size);
    for (size_t i = 0; i < pcm_size; i++) {
        pcm[i] = rand() % 256;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 328; j++) {
            X[i][j] = 0;
        }
    }
}