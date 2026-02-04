#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum TxfmMode {
    TX_4X4,
    TX_8X8,
    TX_16X16,
    TX_32X32,
    N_TXFM_SIZES,
    TX_SWITCHABLE = N_TXFM_SIZES,
    N_TXFM_MODES
};

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *l;
enum TxfmMode tx;
int bpp;
int n;

void init_vars() {
    tx = TX_32X32;
    bpp = 10;
    size_t num_elements = 4 << tx;
    size_t data_size = num_elements * 2;
    l = (uint8_t *)aligned_alloc(16, data_size);
}

extern void loop();

__attribute__((constructor))
static void setup() {
    init_vars();
}