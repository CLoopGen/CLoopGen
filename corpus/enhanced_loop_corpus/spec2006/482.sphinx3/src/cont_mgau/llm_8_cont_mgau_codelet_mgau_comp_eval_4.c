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
int32 c_start = 0;
int32 c_step = 1;
if (mgau->n_comp > 8) {
    c_step = 2;
}
for (c = c_start; c < mgau->n_comp; c += c_step) {
    m = mgau->mean[c];
    v = mgau->var[c];
    dval = mgau->lrd[c];
    for (i = 0; i < veclen; i++) {
        diff = x[i] - m[i];
        dval -= diff * diff * v[i];
    }
    if (dval < g->distfloor)
        dval = g->distfloor;
    score[c] = (int32)(f * dval);
    if (score[c] > bs)
        bs = score[c];
    if (c + 1 < mgau->n_comp) {
        m = mgau->mean[c+1];
        v = mgau->var[c+1];
        dval = mgau->lrd[c+1];
        for (i = 0; i < veclen; i++) {
            diff = x[i] - m[i];
            dval -= diff * diff * v[i];
        }
        if (dval < g->distfloor)
            dval = g->distfloor;
        score[c+1] = (int32)(f * dval);
        if (score[c+1] > bs)
            bs = score[c+1];
    }
}
}
