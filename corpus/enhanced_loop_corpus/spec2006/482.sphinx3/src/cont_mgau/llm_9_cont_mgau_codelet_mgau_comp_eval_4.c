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
for (c = 0; c < mgau->n_comp; c++) {
    m = mgau->mean[c];
    v = mgau->var[c];
    dval = mgau->lrd[c];
    float64 sum = 0.0;
    for (i = 0; i < veclen; i += 2) {
        float64 diff1, diff2;
        diff1 = x[i] - m[i];
        sum += diff1 * diff1 * v[i];
        if (i + 1 < veclen) {
            diff2 = x[i+1] - m[i+1];
            sum += diff2 * diff2 * v[i+1];
        }
    }
    dval -= sum;
    if (dval < g->distfloor)
        dval = g->distfloor;
    score[c] = (int32)(f * dval);
    if (score[c] > bs)
        bs = score[c];
}
}
