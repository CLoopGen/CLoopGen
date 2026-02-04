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



void loop() {
    // Variant 1: Increased loop nesting depth by splitting the inner logic into separate conditional blocks within an additional outer loop
    int point_count = gc_now->num_points;
    for (i = 0; i < point_count; i++) {
        lastpos = gc_now->loc_code[i] << gctx->loc_scale;
        lev = gctx->gain_tab1[gc_now->lev_code[i]];
        gain_inc = gctx->gain_tab2[(i + 1 < point_count ? gc_now->lev_code[i + 1] : gctx->id2exp_offset) - gc_now->lev_code[i] + 15];

        // Introduce nested control: simulate two-phase processing with a fixed-depth loop
        for (int phase = 0; phase < 2; phase++) {
            if (phase == 0) {
                // First phase: process up to lastpos
                for (; pos < lastpos; pos++) {
                    out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
                }
            } else {
                // Second phase: apply gain ramp over loc_size samples
                int endpos = lastpos + gctx->loc_size;
                for (; pos < endpos; pos++) {
                    out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
                    lev *= gain_inc;
                }
            }
        }
    }
}
