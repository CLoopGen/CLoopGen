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
extern int32 k;
extern int32 n_mgau;
extern int32 n_density;
extern int32 blk;
extern float32 *buf;
extern float32 **pbuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_mgau; i++) {
        mgau_t *mg = &g->mgau[i];
        mg->n_comp = n_density;
        mg->mean = pbuf;
        mg->var = (float32**) (pbuf + n_density);
        mg->lrd = (float32*) (buf + n_density * blk);
        mg->mixw = (int32*) (buf + n_density * blk + n_density);
        for (k = 0; k < n_density; k += 2) {
            if (k + 1 < n_density) {
                g->mgau[i].mean[k] = buf;
                buf += blk;
                g->mgau[i].mean[k+1] = buf;
                buf += blk;
            } else {
                g->mgau[i].mean[k] = buf;
                buf += blk;
            }
        }
        pbuf += n_density;
    }
}
