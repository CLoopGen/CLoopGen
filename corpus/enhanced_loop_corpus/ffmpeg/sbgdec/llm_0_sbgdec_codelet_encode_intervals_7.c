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



void loop(){
    // Variant 1: Increased loop nesting depth with outer control loop
    int outer_iter;
    for (outer_iter = 0; outer_iter < 1; outer_iter++) {
        for (i = 0; i < inter->nb_inter; i++) {
            ((((union unaligned_64 *)(edata))->l) = ((inter->inter[i].ts1)));
            edata += 8;
            ((((union unaligned_64 *)(edata))->l) = ((inter->inter[i].ts2)));
            edata += 8;
            ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].type)));
            edata += 4;
            ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].channels)));
            edata += 4;
            switch (inter->inter[i].type) {
              case WS_SINE:
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].f1)));
                edata += 4;
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].f2)));
                edata += 4;
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].a1)));
                edata += 4;
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].a2)));
                edata += 4;
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].phi)));
                edata += 4;
                break;
              case WS_NOISE:
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].a1)));
                edata += 4;
                ((((union unaligned_32 *)(edata))->l) = ((inter->inter[i].a2)));
                edata += 4;
                break;
            }
        }
    }
}
