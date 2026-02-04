#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
    position = 7; // ensures x[-7] is valid and within bounds [0..327]

    // Allocate PCM buffer: need up to (14 * nchannels + 2 * (nchannels-1)) + sizeof(uint16_t)
    size_t pcm_size = 14 * nchannels + 2 * (nchannels - 1) + 2;
    // Scale up to ~64MB of data to get ~0.01 sec runtime (empirical tuning)
    const size_t total_data_mb = 64;
    pcm_size = total_data_mb * 1024 * 1024 / (nchannels * 15); // rough estimate per channel
    if (pcm_size < 1000) pcm_size = 1000;
    pcm = (uint8_t*)calloc(pcm_size, sizeof(uint8_t));
    if (!pcm) exit(1);

    // Fill with dummy aligned 16-bit data
    for (size_t i = 0; i < pcm_size - 1; i += 2) {
        ((uint16_t*)&pcm[i])[0] = (uint16_t)(i * 17);
    }

    // Initialize X array
    memset(X, 0, sizeof(X));
}