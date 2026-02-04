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

// External variables
mgau_model_t *g;
int32 i;
int32 k;
int32 n_mgau;
int32 n_density;
int32 blk;
float32 *buf;
float32 **pbuf;

// Helper allocation pointers to manage memory layout
static float32 *raw_buf_memory = NULL;
static float32 **raw_pbuf_memory = NULL;
static mgau_t *raw_mgau_array = NULL;

void init_vars() {
    // Target: make loop run ~0.01 seconds
    // Estimate: loop runs O(n_mgau * n_density) iterations.
    // On modern CPU, aim for ~10-20 million total inner loop steps => ~0.01s

    n_mgau = 500;
    n_density = 40;
    blk = 32;  // vector dimension per component
    size_t total_data_size = (size_t)n_mgau * n_density * blk;
    size_t total_buf_ptrs = (size_t)n_mgau * n_density;

    // Allocate raw memory for float32 data
    raw_buf_memory = (float32*)calloc(total_data_size, sizeof(float32));
    if (!raw_buf_memory) {
        fprintf(stderr, "Failed to allocate raw_buf_memory\n");
        exit(1);
    }

    // Allocate raw memory for float32** pointers (pbuf array)
    raw_pbuf_memory = (float32**)calloc(total_buf_ptrs, sizeof(float32*));
    if (!raw_pbuf_memory) {
        fprintf(stderr, "Failed to allocate raw_pbuf_memory\n");
        exit(1);
    }

    // Allocate mgau array
    raw_mgau_array = (mgau_t*)calloc(n_mgau, sizeof(mgau_t));
    if (!raw_mgau_array) {
        fprintf(stderr, "Failed to allocate raw_mgau_array\n");
        exit(1);
    }

    // Initialize g structure
    g = (mgau_model_t*)malloc(sizeof(mgau_model_t));
    if (!g) {
        fprintf(stderr, "Failed to allocate g\n");
        exit(1);
    }

    g->n_mgau = n_mgau;
    g->max_comp = n_density;
    g->veclen = blk;
    g->mgau = raw_mgau_array;
    g->distfloor = 1e-6;
    g->frm_sen_eval = 0;
    g->frm_gau_eval = 0;
    g->gau_type = 0;

    // Initialize buf and pbuf
    buf = raw_buf_memory;
    pbuf = raw_pbuf_memory;

    // Initialize all mgau entries
    for (int i_idx = 0; i_idx < n_mgau; i_idx++) {
        g->mgau[i_idx].n_comp = 0;
        g->mgau[i_idx].mean = pbuf + i_idx * n_density;
        g->mgau[i_idx].var = NULL;
        g->mgau[i_idx].lrd = NULL;
        g->mgau[i_idx].mixw = NULL;
    }
}