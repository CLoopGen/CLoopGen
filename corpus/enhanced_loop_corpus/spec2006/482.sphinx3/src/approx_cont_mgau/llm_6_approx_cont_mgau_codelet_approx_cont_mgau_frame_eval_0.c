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
extern int32 *sen_active;
extern int32 *senscr;
extern int32 s;
extern int32 best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_scr[g->n_mgau];
    for (s = 0; s < g->n_mgau; s++) {
        temp_scr[s] = senscr[s];
    }
    for (s = 0; s < g->n_mgau; s++) {
        if (sen_active[s])
            senscr[s] = temp_scr[s] - best;
    }
}
