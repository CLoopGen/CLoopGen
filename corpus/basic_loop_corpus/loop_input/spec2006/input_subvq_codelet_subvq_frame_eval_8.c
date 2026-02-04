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
int32 *senscr;
int32 s;
int32 best;

void init_vars() {
    // Allocate senscr with size approximately 1MB / sizeof(int32) = ~262144 elements
    const int32 array_size = 262144;
    senscr = (int32*)calloc(array_size, sizeof(int32));
    
    // Initialize best to a reasonable value
    best = 1000;

    // Allocate and initialize mgau model structure
    g = (mgau_model_t*)malloc(sizeof(mgau_model_t));
    g->n_mgau = array_size;  // Match senscr size
    g->max_comp = 3;
    g->veclen = 13;
    g->distfloor = 1e-6;
    g->frm_sen_eval = 0;
    g->frm_gau_eval = 0;
    g->gau_type = 0;

    // Allocate mgau array
    g->mgau = (mgau_t*)calloc(g->n_mgau, sizeof(mgau_t));
    for (int i = 0; i < g->n_mgau; i++) {
        g->mgau[i].n_comp = 1;
        g->mgau[i].mean = NULL;
        g->mgau[i].var = NULL;
        g->mgau[i].lrd = NULL;
        g->mgau[i].mixw = NULL;
    }
}