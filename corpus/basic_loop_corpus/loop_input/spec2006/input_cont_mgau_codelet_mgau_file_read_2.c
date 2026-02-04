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
int32 i;
int32 n_mgau;
int32 n_density;
float32 *buf;

void init_vars() {
    n_mgau = 8192;
    n_density = 32768 / sizeof(float32);
    
    size_t total_buf_size = (size_t)n_mgau * n_density * sizeof(float32);
    buf = (float32*)aligned_alloc(32, total_buf_size);
    
    g = (mgau_model_t*)aligned_alloc(32, sizeof(mgau_model_t));
    g->n_mgau = n_mgau;
    g->max_comp = 1;
    g->veclen = 13;
    g->distfloor = 1e-6;
    g->frm_sen_eval = 0;
    g->frm_gau_eval = 0;
    g->gau_type = 0;
    
    g->mgau = (mgau_t*)aligned_alloc(32, n_mgau * sizeof(mgau_t));
    
    for (int32 idx = 0; idx < n_mgau; idx++) {
        g->mgau[idx].n_comp = 1;
        g->mgau[idx].mean = NULL;
        g->mgau[idx].var = NULL;
        g->mgau[idx].mixw = NULL;
        g->mgau[idx].lrd = buf + idx * n_density;
    }
}