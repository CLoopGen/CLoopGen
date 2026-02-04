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
    uint64_t accumulated_amp = 0;
    for (i = ws->next_inter; i < ws->nb_inter; i++) {
        in = &ws->inter[i];
        if (ts < in->ts_start)
            break;
        if (ts >= in->ts_end)
            continue;
        *last = i;
        last = &in->next;
        // Remove some independence: make amp initialization depend on prior iterations
        in->amp = in->amp0 + accumulated_amp;
        accumulated_amp = in->amp; // Loop-carried dependency (WAW and RAW): creates serial dependence
        in->phi = in->phi0;
        in->dphi = in->dphi0;
        // Eliminate independent assignment to phi/dphi by reordering after dependent amp
    }
}
