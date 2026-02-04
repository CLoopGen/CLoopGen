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
extern int32 *senscr;
extern int32 s;
extern int32 best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every 2nd element in two passes)
    int32 n = g->n_mgau;
    // First pass: even indices
    for (int32 i = 0; i < n; i += 2) {
        senscr[i] -= best;
    }
    // Second pass: odd indices
    for (int32 i = 1; i < n; i += 2) {
        senscr[i] -= best;
    }
}
