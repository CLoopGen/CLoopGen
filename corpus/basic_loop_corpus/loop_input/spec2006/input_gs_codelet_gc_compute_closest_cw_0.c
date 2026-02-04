#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int int32;
typedef float float32;
typedef unsigned int uint32;
typedef double float64;

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

gs_t *gs;
float32 *feat;
int32 codeid;
int32 bst_codeid;
float64 diff1;
float64 diff2;
float64 tmp1;
float64 tmp2;
float64 min;
int32 cid;

void init_vars() {
    gs = (gs_t*)malloc(sizeof(gs_t));
    gs->n_mgau = 16;
    gs->n_feat = 13;
    gs->n_code = 256;
    gs->n_density = 256;
    gs->n_featlen = 39;
    gs->n_mbyte = 10;

    feat = (float32*)malloc(gs->n_featlen * sizeof(float32));
    for (int i = 0; i < gs->n_featlen; i++) {
        feat[i] = (float32)(i % 10);
    }

    gs->codeword = (float32**)malloc(gs->n_code * sizeof(float32*));
    for (int i = 0; i < gs->n_code; i++) {
        gs->codeword[i] = (float32*)malloc(gs->n_featlen * sizeof(float32));
        for (int j = 0; j < gs->n_featlen; j++) {
            gs->codeword[i][j] = (float32)((i + j) % 15);
        }
    }

    gs->codemap = (uint32***)malloc(1 * sizeof(uint32***));
    gs->codemap[0] = (uint32**)malloc(1 * sizeof(uint32**));
    gs->codemap[0][0] = (uint32*)malloc(1 * sizeof(uint32));

    gs->fp = fopen("/dev/null", "w");
    if (!gs->fp) gs->fp = stderr;

    gs->mgau_sl = (int32*)malloc(gs->n_mgau * sizeof(int32));
    for (int i = 0; i < gs->n_mgau; i++) {
        gs->mgau_sl[i] = i;
    }

    codeid = 0;
    bst_codeid = 0;
    diff1 = 0.0;
    diff2 = 0.0;
    tmp1 = 1e30;
    tmp2 = 1e30;
    min = 1e30;
    cid = 0;
}