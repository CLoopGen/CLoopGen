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
    gain_inc = gctx->gain_tab2[(i + 1 < gc_now->num_points ? gc_now->lev_code[i + 1] : gctx->id2exp_offset) - gc_now->lev_code[i] + 15];
    for (; pos < lastpos; pos++)
        out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
    for (; pos < lastpos + gctx->loc_size; pos++) {
        out[pos] = (in[pos] * gc_scale + prev[pos]) * lev;
        lev *= gain_inc;
    }
}

}
