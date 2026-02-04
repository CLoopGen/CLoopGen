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
    float64 temp_mins[2];
    int32 temp_codes[2];
    for (codeid = 0; codeid < gs->n_code; codeid += 2) {
        tmp1 = 0;
        tmp2 = 0;
        for (cid = 0; cid < gs->n_featlen; cid++) {
            float64 cw1 = gs->codeword[codeid][cid];
            float64 cw2 = gs->codeword[codeid + 1][cid];
            diff1 = feat[cid] - cw1;
            diff2 = feat[cid] - cw2;
            tmp1 += diff1 * diff1;
            tmp2 += diff2 * diff2;
        }
        temp_mins[0] = tmp1;
        temp_mins[1] = tmp2;
        temp_codes[0] = codeid;
        temp_codes[1] = codeid + 1;
        for (int i = 0; i < 2; i++) {
            if (temp_mins[i] < min) {
                min = temp_mins[i];
                bst_codeid = temp_codes[i];
            }
        }
    }
}
