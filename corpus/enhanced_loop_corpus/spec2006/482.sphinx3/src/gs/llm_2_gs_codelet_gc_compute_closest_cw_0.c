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
for (codeid = 0; codeid < gs->n_code; codeid += 2) {
    tmp1 = 0;
    tmp2 = 0;
    // Access feat and codeword arrays with stride of 2, processing even indices only
    for (cid = 0; cid < gs->n_featlen; cid += 2) {
        diff1 = feat[cid] - (gs->codeword[codeid][cid]);
        tmp1 += diff1 * diff1;
        diff2 = feat[cid] - (gs->codeword[codeid + 1][cid]);
        tmp2 += diff2 * diff2;
        // Handle odd index if within bounds
        if (cid + 1 < gs->n_featlen) {
            diff1 = feat[cid + 1] - (gs->codeword[codeid][cid + 1]);
            tmp1 += diff1 * diff1;
            diff2 = feat[cid + 1] - (gs->codeword[codeid + 1][cid + 1]);
            tmp2 += diff2 * diff2;
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
}
}
