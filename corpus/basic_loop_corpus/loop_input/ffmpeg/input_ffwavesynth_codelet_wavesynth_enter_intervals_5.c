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

struct ws_interval *g_inter = NULL;
int32_t *g_sin = NULL;
struct wavesynth_context *ws = NULL;
int *last = NULL;
int i;

void init_vars() {
    const size_t data_size = 1 << 20;
    const int nb_inter = (data_size / sizeof(struct ws_interval)) + 1;

    g_inter = aligned_alloc(64, nb_inter * sizeof(struct ws_interval));
    g_sin = aligned_alloc(64, 8192 * sizeof(int32_t));

    for (int idx = 0; idx < nb_inter; ++idx) {
        g_inter[idx].ts_start = idx * 1000LL;
        g_inter[idx].ts_end = (idx + 1) * 1000LL;
        g_inter[idx].phi0 = 0x12345678ULL + idx;
        g_inter[idx].dphi0 = 0x23456789ULL + idx;
        g_inter[idx].ddphi = 0x3456789AULL + idx;
        g_inter[idx].amp0 = 0x456789ABULL + idx;
        g_inter[idx].damp = 0x56789ABCULL + idx;
        g_inter[idx].phi = 0x6789ABCDULL + idx;
        g_inter[idx].dphi = 0x789ABCDEULL + idx;
        g_inter[idx].amp = 0x89ABCDEFULL + idx;
        g_inter[idx].channels = 0xFFFFFFFFU;
        g_inter[idx].type = (idx & 1) ? WS_SINE : WS_NOISE;
        g_inter[idx].next = (idx == nb_inter - 1) ? -1 : idx + 1;
    }

    ws = aligned_alloc(64, sizeof(struct wavesynth_context));
    ws->cur_ts = 0;
    ws->next_ts = 1000LL;
    ws->sin = g_sin;
    ws->inter = g_inter;
    ws->dither_state = 0x12345678U;
    ws->pink_state = 0x87654321U;
    for (int j = 0; j < 128; ++j)
        ws->pink_pool[j] = (int32_t)(0xABCDEF01U + j);
    ws->pink_need = 64;
    ws->pink_pos = 0;
    ws->nb_inter = nb_inter;
    ws->cur_inter = 0;
    ws->next_inter = -1;

    last = &(g_inter[nb_inter - 1].next);
    i = 0;
}