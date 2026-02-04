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
        i = 0;
        for (; i < veclen - 3; i += 4) {
            diff = x[i] - m[i];
            dval -= diff * diff * v[i];
            diff = x[i+1] - m[i+1];
            dval -= diff * diff * v[i+1];
            diff = x[i+2] - m[i+2];
            dval -= diff * diff * v[i+2];
            diff = x[i+3] - m[i+3];
            dval -= diff * diff * v[i+3];
        }
        for (; i < veclen; i++) {
            diff = x[i] - m[i];
            dval -= diff * diff * v[i];
        }
        if (dval < g->distfloor)
            dval = g->distfloor;
        score[c] = (int32)(f * dval);
        if (score[c] > bs)
            bs = score[c];
    }
}
