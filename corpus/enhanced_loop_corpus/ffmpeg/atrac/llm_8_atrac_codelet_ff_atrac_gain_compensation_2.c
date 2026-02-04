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
    // Variant 1: Increased computational intensity by unrolling inner loops and increasing arithmetic operations
    for (i = 0; i < gc_now->num_points; i++) {
        lastpos = gc_now->loc_code[i] << gctx->loc_scale;
        lev = gctx->gain_tab1[gc_now->lev_code[i]];
        gain_inc = gctx->gain_tab2[(i + 1 < gc_now->num_points ? gc_now->lev_code[i + 1] : gctx->id2exp_offset) - gc_now->lev_code[i] + 15];
        
        // Unroll the first loop by processing 4 elements per iteration if possible
        int limit1 = lastpos - 3;
        for (; pos < limit1; pos += 4) {
            out[pos]     = (in[pos] * gc_scale + prev[pos]) * lev;
            out[pos + 1] = (in[pos + 1] * gc_scale + prev[pos + 1]) * lev;
            out[pos + 2] = (in[pos + 2] * gc_scale + prev[pos + 2]) * lev;
            out[pos + 3] = (in[pos + 3] * gc_scale + prev[pos + 3]) * lev;
        }
        // Handle remaining elements in original manner
        for (; pos < lastpos; pos++)
            out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;

        int limit2 = lastpos + gctx->loc_size - 3;
        for (; pos < limit2; pos += 4) {
            float temp1 = (in[pos] * gc_scale + prev[pos]) * lev;
            lev *= gain_inc;
            float temp2 = (in[pos + 1] * gc_scale + prev[pos + 1]) * lev;
            lev *= gain_inc;
            float temp3 = (in[pos + 2] * gc_scale + prev[pos + 2]) * lev;
            lev *= gain_inc;
            float temp4 = (in[pos + 3] * gc_scale + prev[pos + 3]) * lev;
            lev *= gain_inc;
            out[pos]     = temp1;
            out[pos + 1] = temp2;
            out[pos + 2] = temp3;
            out[pos + 3] = temp4;
        }
        for (; pos < lastpos + gctx->loc_size; pos++) {
            out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
            lev *= gain_inc;
        }
    }
}
