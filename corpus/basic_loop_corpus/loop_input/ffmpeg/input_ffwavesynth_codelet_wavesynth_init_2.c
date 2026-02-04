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

struct ws_interval *global_inter;
int32_t *global_sin;
struct wavesynth_context *ws;
int i;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB to target ~0.01s runtime
    const int nb_elements = (int)(data_size / sizeof(struct ws_interval));
    
    global_inter = aligned_alloc(32, nb_elements * sizeof(struct ws_interval));
    global_sin = aligned_alloc(32, 8192 * sizeof(int32_t));

    for (int idx = 0; idx < nb_elements; idx++) {
        global_inter[idx].ts_start = idx * 1000LL;
        global_inter[idx].ts_end = idx * 1000LL + 500LL;
        global_inter[idx].phi0 = 0x100000000ULL + (idx % 1000);
        global_inter[idx].dphi0 = 0x20000000ULL;
        global_inter[idx].ddphi = 0x1000000ULL;
        global_inter[idx].amp0 = 0x80000000ULL;
        global_inter[idx].damp = 0x4000000ULL;
        global_inter[idx].phi = global_inter[idx].phi0;
        global_inter[idx].dphi = global_inter[idx].dphi0;
        global_inter[idx].amp = global_inter[idx].amp0;
        global_inter[idx].channels = 1U << (idx % 16);
        global_inter[idx].type = (idx % 3 == 0) ? WS_NOISE : WS_SINE;
        global_inter[idx].next = (idx + 1) % nb_elements;
    }

    for (int idx = 0; idx < 8192; idx++) {
        global_sin[idx] = (int32_t)((0x7fffffffULL * ((idx % 4096) - 2048)) / 2048);
    }

    ws = aligned_alloc(32, sizeof(struct wavesynth_context));
    ws->cur_ts = 0;
    ws->next_ts = 1000;
    ws->sin = global_sin;
    ws->inter = global_inter;
    ws->dither_state = 0x12345678U;
    ws->pink_state = 0x87654321U;
    for (int idx = 0; idx < 128; idx++) {
        ws->pink_pool[idx] = (int32_t)(0x7fffffffU & (idx * 0x1234567U));
    }
    ws->pink_need = 0;
    ws->pink_pos = 0;
    ws->nb_inter = nb_elements;
    ws->cur_inter = 0;
    ws->next_inter = 1;
}