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


extern struct wavesynth_context *ws;
extern int64_t ts;
extern int *last;
extern int i;
extern struct ws_interval *in;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with prefetching and linear traversal
    struct ws_interval *inter_array = ws->inter;
    int nb_inter = ws->nb_inter;
    int next_inter = ws->next_inter;
    int64_t local_ts = ts;

    for (i = next_inter; i < nb_inter; i++) {
        struct ws_interval *in_ptr = &inter_array[i]; // Consecutive access pattern

        if (local_ts < in_ptr->ts_start)
            break;
        if (local_ts >= in_ptr->ts_end)
            continue;

        *last = i;
        last = &in_ptr->next;
        in_ptr->phi = in_ptr->phi0;
        in_ptr->dphi = in_ptr->dphi0;
        in_ptr->amp = in_ptr->amp0;
    }
}
