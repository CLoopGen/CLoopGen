#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

typedef unsigned int uint32;

typedef struct gs_s {
    int32 n_mgau;
    int32 n_feat;
    int32 n_code;
    int32 n_density;
    int32 n_featlen;
    int32 n_mbyte;
    float32 **codeword;
    uint32 ***codemap;
    FILE *fp;
    int32 *mgau_sl;
} gs_t;

typedef double float64;

extern gs_t *gs;
extern float32 *feat;
extern int32 codeid;
extern int32 bst_codeid;
extern float64 diff1;
extern float64 diff2;
extern float64 tmp1;
extern float64 tmp2;
extern float64 min;
extern int32 cid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (codeid = 0; codeid < gs->n_code; codeid += 4) {
    tmp1 = 0;
    tmp2 = 0;
    float64 tmp3 = 0;
    float64 tmp4 = 0;
    for (cid = 0; cid < gs->n_featlen; cid++) {
        diff1 = feat[cid] - (gs->codeword[codeid][cid]);
        tmp1 += diff1 * diff1;
        diff2 = feat[cid] - (gs->codeword[codeid + 1][cid]);
        tmp2 += diff2 * diff2;
        if (codeid + 2 < gs->n_code) {
            diff1 = feat[cid] - (gs->codeword[codeid + 2][cid]);
            tmp3 += diff1 * diff1;
        }
        if (codeid + 3 < gs->n_code) {
            diff2 = feat[cid] - (gs->codeword[codeid + 3][cid]);
            tmp4 += diff2 * diff2;
        }
    }
    if (tmp1 < min) {
        min = tmp1;
        bst_codeid = codeid;
    }
    if (tmp2 < min) {
        min = tmp2;
        bst_codeid = codeid + 1;
    }
    if (codeid + 2 < gs->n_code && tmp3 < min) {
        min = tmp3;
        bst_codeid = codeid + 2;
    }
    if (codeid + 3 < gs->n_code && tmp4 < min) {
        min = tmp4;
        bst_codeid = codeid + 3;
    }
}
}
