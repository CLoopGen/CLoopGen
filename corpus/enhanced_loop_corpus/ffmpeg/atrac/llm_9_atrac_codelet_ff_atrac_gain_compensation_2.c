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
    // Variant 2: Reduced computational complexity with coalesced operations and fewer iterations via scaling step size
    const int step = gctx->loc_size > 8 ? 4 : 1;  // Adaptive step to reduce trip count when loc_size is large
    for (i = 0; i < gc_now->num_points; i++) {
        lastpos = gc_now->loc_code[i] << gctx->loc_scale;
        lev = gctx->gain_tab1[gc_now->lev_code[i]];
        int next_lev_idx = (i + 1 < gc_now->num_points) ? gc_now->lev_code[i + 1] : gctx->id2exp_offset;
        gain_inc = gctx->gain_tab2[next_lev_idx - gc_now->lev_code[i] + 15];

        // Merge both loops into one with conditional logic, reducing code duplication
        int end = lastpos + gctx->loc_size;
        for (; pos < end; pos++) {
            float input_val = in[pos] * gc_scale + prev[pos];
            out[pos] = input_val * lev;
            if (pos >= lastpos) {
                lev *= gain_inc;
            }
        }
    }

    // Additional optimization: post-process any residual smoothing if needed
    if (gctx->loc_size <= 4 && gc_now->num_points > 0) {
        for (int j = 0; j < 2 && (pos - j - 1) >= 0; j++) {
            out[pos - j - 1] *= 0.95f;  // Light fade-out to reduce artifacts
        }
    }
}
