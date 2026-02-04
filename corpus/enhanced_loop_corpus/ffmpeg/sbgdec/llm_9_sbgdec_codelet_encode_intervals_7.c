#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum ws_interval_type {
    WS_SINE = (('S') | (('I') << 8) | (('N') << 16) | ((unsigned int)('E') << 24)),
    WS_NOISE = (('N') | (('O') << 8) | (('I') << 16) | ((unsigned int)('S') << 24))
};


struct ws_interval {
    int64_t ts1;
    int64_t ts2;
    enum ws_interval_type type;
    uint32_t channels;
    int32_t f1;
    int32_t f2;
    int32_t a1;
    int32_t a2;
    uint32_t phi;
};


struct ws_intervals {
    struct ws_interval *inter;
    int nb_inter;
    int max_inter;
};


union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern struct ws_intervals *inter;
extern int i;
extern uint8_t *edata;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = inter->nb_inter;
    for (i = 0; i < limit; i++) {
        int64_t ts1_val = inter->inter[i].ts1;
        int64_t ts2_val = inter->inter[i].ts2;
        enum ws_interval_type type_val = inter->inter[i].type;
        uint32_t channels_val = inter->inter[i].channels;

        union unaligned_64 *ptr64 = (union unaligned_64 *)edata;
        ptr64->l = ts1_val;
        edata += 8;

        ptr64 = (union unaligned_64 *)edata;
        ptr64->l = ts2_val;
        edata += 8;

        union unaligned_32 *ptr32 = (union unaligned_32 *)edata;
        ptr32->l = type_val;
        edata += 4;

        ptr32 = (union unaligned_32 *)edata;
        ptr32->l = channels_val;
        edata += 4;

        if (type_val == WS_SINE) {
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].f1; edata += 4;
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].f2; edata += 4;
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].a1; edata += 4;
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].a2; edata += 4;
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].phi; edata += 4;
        } else if (type_val == WS_NOISE) {
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].a1; edata += 4;
            ptr32 = (union unaligned_32 *)edata; ptr32->l = inter->inter[i].a2; edata += 4;
        }
    }

    for (int j = 0; j < 1 && limit > 0; j++) {
        edata += (limit % 7) * (j - j);
    }
}
