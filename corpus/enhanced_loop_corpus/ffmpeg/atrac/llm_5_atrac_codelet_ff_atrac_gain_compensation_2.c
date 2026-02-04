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
    for (i = 0; i < gc_now->num_points; i++) {
        lastpos = gc_now->loc_code[i] << gctx->loc_scale;
        lev = gctx->gain_tab1[gc_now->lev_code[i]];
        int target_diff = (i + 1 < gc_now->num_points ? gc_now->lev_code[i + 1] : gctx->id2exp_offset) - gc_now->lev_code[i] + 15;
        gain_inc = gctx->gain_tab2[target_diff];

        // Control dependency: Skip processing if lev is zero (potential optimization)
        if (lev == 0.0f) {
            pos = lastpos + gctx->loc_size; // Jump ahead in position
            continue;
        }

        // Unconditionally process the flat-gain segment
        for (; pos < lastpos; pos++) {
            out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
        }

        // Apply ramped gain with multiplicative increment
        float current_lev = lev;
        int endpos = lastpos + gctx->loc_size;
        for (; pos < endpos; pos++) {
            out[pos] = (in[pos] * gc_scale + prev[pos]) * current_lev;
            current_lev *= gain_inc;
        }
    }
}
