#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

typedef struct {
    int32 n_comp;
    float32 **mean;
    float32 **var;
    float32 *lrd;
    int32 *mixw;
} mgau_t;

typedef double float64;

typedef struct {
    int32 n_mgau;
    int32 max_comp;
    int32 veclen;
    mgau_t *mgau;
    float64 distfloor;
    int32 frm_sen_eval;
    int32 frm_gau_eval;
    int32 gau_type;
} mgau_model_t;

extern mgau_model_t *g;
extern float32 *x;
extern int32 *score;
extern mgau_t *mgau;
extern int32 veclen;
extern float32 *m;
extern float32 *v;
extern float64 dval;
extern float64 diff;
extern float64 f;
extern int32 bs;
extern int32 i;
extern int32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float64 local_dval;
    int32 local_bs = 0x80000000; // Local accumulator to remove loop-carried WAW on 'bs'
    for (c = 0; c < mgau->n_comp; c++) {
        m = mgau->mean[c];
        v = mgau->var[c];
        local_dval = mgau->lrd[c];
        for (i = 0; i < veclen; i++) {
            float64 local_diff = (float64)(x[i] - m[i]); // Eliminate reuse of 'diff' (breaks RAW)
            local_dval -= local_diff * local_diff * (float64)v[i]; // All temporaries are local
        }
        if (local_dval < g->distfloor)
            local_dval = g->distfloor;
        int32 computed_score = (int32)(f * local_dval); // Break WAR/WAW on 'score[c]' via temp
        score[c] = computed_score;
        if (computed_score > local_bs)
            local_bs = computed_score; // Reduce loop-carried dependency on 'bs'
    }
    bs = local_bs; // Final write to shared 'bs' after loop
}
