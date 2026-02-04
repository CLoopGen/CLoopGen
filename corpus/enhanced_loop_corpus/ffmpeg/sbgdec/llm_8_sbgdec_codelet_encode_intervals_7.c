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
    int start = 0;
    int step = 1;
    for (i = start; i < inter->nb_inter; i += step) {
        union unaligned_64 *u64_ts1 = (union unaligned_64 *)(edata);
        u64_ts1->l = inter->inter[i].ts1;
        edata += 8;

        union unaligned_64 *u64_ts2 = (union unaligned_64 *)(edata);
        u64_ts2->l = inter->inter[i].ts2;
        edata += 8;

        union unaligned_32 *u32_type = (union unaligned_32 *)(edata);
        u32_type->l = inter->inter[i].type;
        edata += 4;

        union unaligned_32 *u32_channels = (union unaligned_32 *)(edata);
        u32_channels->l = inter->inter[i].channels;
        edata += 4;

        if (inter->inter[i].type == WS_SINE) {
            union unaligned_32 *f1 = (union unaligned_32 *)(edata);
            f1->l = inter->inter[i].f1;
            edata += 4;

            union unaligned_32 *f2 = (union unaligned_32 *)(edata);
            f2->l = inter->inter[i].f2;
            edata += 4;

            union unaligned_32 *a1 = (union unaligned_32 *)(edata);
            a1->l = inter->inter[i].a1;
            edata += 4;

            union unaligned_32 *a2 = (union unaligned_32 *)(edata);
            a2->l = inter->inter[i].a2;
            edata += 4;

            union unaligned_32 *phi = (union unaligned_32 *)(edata);
            phi->l = inter->inter[i].phi;
            edata += 4;
        } else if (inter->inter[i].type == WS_NOISE) {
            union unaligned_32 *a1 = (union unaligned_32 *)(edata);
            a1->l = inter->inter[i].a1;
            edata += 4;

            union unaligned_32 *a2 = (union unaligned_32 *)(edata);
            a2->l = inter->inter[i].a2;
            edata += 4;
        }
    }
}
