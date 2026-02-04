#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGCContext {
    float gain_tab1[16];
    float gain_tab2[31];
    int id2exp_offset;
    int loc_scale;
    int loc_size;
} AtracGCContext;

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGCContext *gctx;
extern float *in;
extern float *prev;
extern AtracGainInfo *gc_now;
extern float *out;
extern float lev;
extern float gc_scale;
extern float gain_inc;
extern int i;
extern int pos;
extern int lastpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_lev_diff, current_lev_idx;
    float current_gain, next_gain_inc;
    for (i = 0; i < gc_now->num_points; i++) {
        lastpos = gc_now->loc_code[i] << gctx->loc_scale;
        current_lev_idx = gc_now->lev_code[i];
        current_gain = gctx->gain_tab1[current_lev_idx];
        next_lev_diff = (i + 1 < gc_now->num_points) ? gc_now->lev_code[i + 1] : gctx->id2exp_offset;
        next_gain_inc = gctx->gain_tab2[next_lev_diff - current_lev_idx + 15];
        for (; pos < lastpos; pos++) {
            out[pos] = (in[pos] * gc_scale + prev[pos]) * current_gain;
        }
        for (; pos < lastpos + gctx->loc_size; pos++) {
            out[pos] = (in[pos] * gc_scale + prev[pos]) * current_gain;
            current_gain *= next_gain_inc;
        }
    }
}
