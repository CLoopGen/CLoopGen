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
    int64_t prev_ts2 = 0;
    for (i = 0; i < inter->nb_inter; i++) {
        struct ws_interval *curr = &inter->inter[i];
        
        int64_t offset_ts1 = curr->ts1 ^ prev_ts2;
        ((union unaligned_64 *)edata)->l = offset_ts1;
        edata += 8;
        ((union unaligned_64 *)edata)->l = curr->ts2;
        edata += 8;
        prev_ts2 = curr->ts2;

        uint32_t packed_header = ((uint32_t)curr->type) | (curr->channels << 16);
        ((union unaligned_32 *)edata)->l = packed_header;
        edata += 4;

        switch (curr->type) {
            case WS_SINE: {
                int32_t f_diff = curr->f2 - curr->f1;
                ((union unaligned_32 *)edata)->l = curr->f1;
                edata += 4;
                ((union unaligned_32 *)edata)->l = f_diff;
                edata += 4;
                ((union unaligned_32 *)edata)->l = curr->a1;
                edata += 4;
                ((union unaligned_32 *)edata)->l = curr->a2;
                edata += 4;
                ((union unaligned_32 *)edata)->l = curr->phi;
                edata += 4;
                break;
            }
            case WS_NOISE: {
                uint32_t combined_amp = ((uint32_t)(curr->a1 & 0xFFFF)) | ((uint32_t)(curr->a2 & 0xFFFF) << 16);
                ((union unaligned_32 *)edata)->l = combined_amp;
                edata += 4;
                break;
            }
        }
    }
}
