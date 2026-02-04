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
int nsamples;
int nchannels;
int c;

void init_vars() {
    nchannels = 2;
    position = 320;
    nsamples = 320;

    pcm = aligned_alloc(16, (nsamples * nchannels * 2) + 16 * nchannels);
    if (!pcm) exit(1);

    for (int i = 0; i < (nsamples * nchannels * 2) + 16 * nchannels; i++) {
        pcm[i] = i & 0xFF;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 328; j++) {
            X[i][j] = 0;
        }
    }
}