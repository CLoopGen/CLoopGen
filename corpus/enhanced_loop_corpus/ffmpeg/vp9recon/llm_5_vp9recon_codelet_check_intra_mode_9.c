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

extern uint8_t *l;
extern enum TxfmMode tx;
extern int bpp;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < (4 << tx); n++) {
        if (tx >= TX_16X16 || bpp > 8) {
            (((av_alias16 *)(&(l)[n * 2]))->u16 = (((128 << (bpp - 8)) + 1)));
        } else {
            continue;
        }
    }
}
