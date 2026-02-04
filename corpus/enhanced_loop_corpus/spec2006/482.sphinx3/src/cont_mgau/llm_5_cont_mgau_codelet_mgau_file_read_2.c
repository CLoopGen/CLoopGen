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
extern int32 i;
extern int32 n_mgau;
extern int32 n_density;
extern float32 *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_mgau; i++) {
        if (g == NULL) continue;
        if (g->mgau == NULL) continue;
        g->mgau[i].lrd = buf;
        buf += n_density;
    }
}
