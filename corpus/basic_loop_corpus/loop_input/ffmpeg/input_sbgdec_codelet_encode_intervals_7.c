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

struct ws_intervals *inter;
int i;
uint8_t *edata;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024;
    const int avg_interval_size = 8 + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4;
    const int num_intervals = total_data_size / avg_interval_size;

    inter = (struct ws_intervals *)calloc(1, sizeof(struct ws_intervals));
    if (!inter) exit(1);

    inter->inter = (struct ws_interval *)calloc(num_intervals, sizeof(struct ws_interval));
    if (!inter->inter) exit(1);

    inter->nb_inter = num_intervals;
    inter->max_inter = num_intervals;

    edata = (uint8_t *)malloc(total_data_size);
    if (!edata) exit(1);

    for (int idx = 0; idx < num_intervals; idx++) {
        inter->inter[idx].ts1 = 1000 + idx * 10;
        inter->inter[idx].ts2 = 2000 + idx * 10;
        inter->inter[idx].type = (idx % 3 == 0) ? WS_NOISE : WS_SINE;
        inter->inter[idx].channels = 0x12345678U;
        inter->inter[idx].f1 = 440 + idx;
        inter->inter[idx].f2 = 880 + idx;
        inter->inter[idx].a1 = 0xABCD1234;
        inter->inter[idx].a2 = 0x5678ABCD;
        inter->inter[idx].phi = 0xCAFEBABE;
    }
}