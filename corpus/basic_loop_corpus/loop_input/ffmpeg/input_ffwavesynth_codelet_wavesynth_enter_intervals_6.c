#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum ws_interval_type {
    WS_SINE = (('S') | (('I') << 8) | (('N') << 16) | ((unsigned int)('E') << 24)),
    WS_NOISE = (('N') | (('O') << 8) | (('I') << 16) | ((unsigned int)('S') << 24))
};

struct ws_interval {
    int64_t ts_start;
    int64_t ts_end;
    uint64_t phi0;
    uint64_t dphi0;
    uint64_t ddphi;
    uint64_t amp0;
    uint64_t damp;
    uint64_t phi;
    uint64_t dphi;
    uint64_t amp;
    uint32_t channels;
    enum ws_interval_type type;
    int next;
};

struct wavesynth_context {
    int64_t cur_ts;
    int64_t next_ts;
    int32_t *sin;
    struct ws_interval *inter;
    uint32_t dither_state;
    uint32_t pink_state;
    int32_t pink_pool[128];
    unsigned int pink_need;
    unsigned int pink_pos;
    int nb_inter;
    int cur_inter;
    int next_inter;
};

struct wavesynth_context *ws;
int64_t ts;
int *last;
int i;
struct ws_interval *in;

#define DATA_SIZE_MB 64
#define NUM_INTERVALS (DATA_SIZE_MB * (1<<20) / sizeof(struct ws_interval))

static struct ws_interval intervals[NUM_INTERVALS];
static int32_t sin_table[8192];

void init_vars() {
    ws = (struct wavesynth_context *)calloc(1, sizeof(struct wavesynth_context));
    if (!ws) exit(1);

    ws->inter = intervals;
    ws->sin = sin_table;
    ws->nb_inter = NUM_INTERVALS;
    ws->next_inter = 0;
    ws->cur_inter = 0;
    ws->cur_ts = 0;
    ws->next_ts = 1000000;

    ts = 500000;

    for (int idx = 0; idx < NUM_INTERVALS; idx++) {
        struct ws_interval *iv = &intervals[idx];
        iv->ts_start = idx * 1000;
        iv->ts_end = iv->ts_start + 800;
        iv->phi0 = 0x100000000ULL + (idx << 20);
        iv->dphi0 = 0x10000000ULL + (idx << 10);
        iv->ddphi = 0x100000;
        iv->amp0 = 0x80000000ULL - (idx << 12);
        iv->damp = 0x10000;
        iv->channels = 1;
        iv->type = (idx % 2) ? WS_SINE : WS_NOISE;
        iv->next = -1;
    }

    last = &intervals[0].next;
    in = NULL;
    i = 0;
}