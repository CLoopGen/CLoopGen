#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t *iv2p;
aes_block_t tmp;
aes_block_t *inp;

static aes_block_t inp_buffer[4096];
static aes_block_t iv2p_buffer[4096];

void init_vars() {
    for (int i = 0; i < 4096; ++i) {
        inp_buffer[i].data[0] = 0xdeadbeefUL + i;
        inp_buffer[i].data[1] = 0xbadc0de5UL + i;
        iv2p_buffer[i].data[0] = 0x12345678UL + i;
        iv2p_buffer[i].data[1] = 0xabcdef01UL + i;
    }
    inp = inp_buffer;
    iv2p = iv2p_buffer;
    tmp.data[0] = 0;
    tmp.data[1] = 0;
    n = 0;
}