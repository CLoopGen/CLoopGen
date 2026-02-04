#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef float float32;
typedef double float64;

typedef struct {
    int32 n_comp;
    float32 **mean;
    float32 **var;
    float32 *lrd;
    int32 *mixw;
} mgau_t;

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

mgau_model_t *g;
float32 *x;
int32 *score;
mgau_t *mgau;
int32 veclen;
float32 *m;
float32 *v;
float64 dval;
float64 diff;
float64 f;
int32 bs;
int32 i;
int32 c;

void init_vars() {
    veclen = 128;
    int32 n_comp_max = 8;
    int32 data_size = 1 << 20;
    int32 num_mgau = 1;

    g = (mgau_model_t*)calloc(1, sizeof(mgau_model_t));
    mgau = (mgau_t*)calloc(num_mgau, sizeof(mgau_t));
    g->mgau = mgau;
    g->n_mgau = num_mgau;
    g->max_comp = n_comp_max;
    g->veclen = veclen;
    g->distfloor = -50.0;
    g->frm_sen_eval = 0;
    g->frm_gau_eval = 0;
    g->gau_type = 0;

    x = (float32*)malloc(veclen * sizeof(float32));
    for (i = 0; i < veclen; i++) {
        x[i] = (float32)(i % 100) * 0.1f;
    }

    f = 100.0;

    bs = -2147483648;

    for (int idx = 0; idx < num_mgau; idx++) {
        mgau[idx].n_comp = n_comp_max;
        mgau[idx].lrd = (float32*)malloc(n_comp_max * sizeof(float32));
        mgau[idx].mixw = (int32*)malloc(n_comp_max * sizeof(int32));
        mgau[idx].mean = (float32**)malloc(n_comp_max * sizeof(float32*));
        mgau[idx].var = (float32**)malloc(n_comp_max * sizeof(float32*));
        for (c = 0; c < n_comp_max; c++) {
            mgau[idx].lrd[c] = (float32)(-c * 10);
            mgau[idx].mixw[c] = c;
            mgau[idx].mean[c] = (float32*)malloc(veclen * sizeof(float32));
            mgau[idx].var[c] = (float32*)malloc(veclen * sizeof(float32));
            for (i = 0; i < veclen; i++) {
                mgau[idx].mean[c][i] = (float32)((i + c) % 50) * 0.2f;
                mgau[idx].var[c][i] = (float32)(1.0f / (1.0f + (i % 10))) * 0.5f;
            }
        }
        score = (int32*)malloc(n_comp_max * sizeof(int32));
        for (c = 0; c < n_comp_max; c++) {
            score[c] = 0;
        }
    }

    m = NULL;
    v = NULL;
    dval = 0.0;
    diff = 0.0;
}