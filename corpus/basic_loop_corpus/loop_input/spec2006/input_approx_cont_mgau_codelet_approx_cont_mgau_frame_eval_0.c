#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
int32 *sen_active;
int32 *senscr;
int32 s;
int32 best;

void init_vars() {
    const int32 N_MGAU = 1 << 20; 

    g = (mgau_model_t *)calloc(1, sizeof(mgau_model_t));
    g->n_mgau = N_MGAU;
    g->max_comp = 1;
    g->veclen = 1;
    g->distfloor = 1e-5;
    g->frm_sen_eval = 0;
    g->frm_gau_eval = 0;
    g->gau_type = 0;

    g->mgau = (mgau_t *)calloc(N_MGAU, sizeof(mgau_t));
    for (int32 i = 0; i < N_MGAU; ++i) {
        g->mgau[i].n_comp = 1;
        g->mgau[i].mean = (float32 **)calloc(1, sizeof(float32 *));
        g->mgau[i].var = (float32 **)calloc(1, sizeof(float32 *));
        g->mgau[i].lrd = (float32 *)calloc(1, sizeof(float32));
        g->mgau[i].mixw = (int32 *)calloc(1, sizeof(int32));
        g->mgau[i].mean[0] = (float32 *)calloc(1, sizeof(float32));
        g->mgau[i].var[0] = (float32 *)calloc(1, sizeof(float32));
    }

    sen_active = (int32 *)calloc(N_MGAU, sizeof(int32));
    senscr = (int32 *)calloc(N_MGAU, sizeof(int32));

    for (int32 i = 0; i < N_MGAU; ++i) {
        sen_active[i] = 1;
        senscr[i] = i % 1000;
    }

    best = 100;
}