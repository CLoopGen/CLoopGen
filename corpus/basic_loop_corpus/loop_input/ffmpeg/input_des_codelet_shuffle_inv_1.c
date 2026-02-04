#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t in;
uint8_t *shuffle;
int shuffle_len;
int i;
uint64_t res;

void init_vars() {
    shuffle_len = 64;
    shuffle = malloc(shuffle_len * sizeof(uint8_t));
    if (!shuffle) {
        exit(1);
    }
    for (int idx = 0; idx < shuffle_len; idx++) {
        shuffle[idx] = (uint8_t)(idx);
    }
    in = UINT64_C(0xDEADBEEFCAFEBABE);
    res = 0;
}