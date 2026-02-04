#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

gs_t *gs;
int n;
uint32 map;
int32 bit_id;
int32 nc;

void init_vars() {
    n = 32;
    map = 0xFFFFFFFF;
    bit_id = 0;
    nc = 0;

    gs = (gs_t*)malloc(sizeof(gs_t));
    gs->n_mgau = 1000000;
    gs->n_feat = 1;
    gs->n_code = 1;
    gs->n_density = 1;
    gs->n_featlen = 1;
    gs->n_mbyte = 1;
    gs->fp = NULL;

    gs->mgau_sl = (int32*)malloc(gs->n_mgau * sizeof(int32));
    memset(gs->mgau_sl, 0, gs->n_mgau * sizeof(int32));

    gs->codeword = (float32**)malloc(1 * sizeof(float32*));
    gs->codeword[0] = (float32*)malloc(1 * sizeof(float32));
    gs->codemap = (uint32***)malloc(1 * sizeof(uint32**));
    gs->codemap[0] = (uint32**)malloc(1 * sizeof(uint32*));
    gs->codemap[0][0] = (uint32*)malloc(1 * sizeof(uint32));
}