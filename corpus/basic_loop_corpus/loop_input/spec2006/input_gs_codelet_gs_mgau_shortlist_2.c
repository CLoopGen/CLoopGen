#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
int32 bit_id;
int32 nc;

void init_vars() {
    n = 10000000;  // Adjusted for ~0.01 sec runtime
    nc = 0;

    gs = (gs_t*)malloc(sizeof(gs_t));
    gs->n_mgau = n;
    gs->n_feat = 1;
    gs->n_code = 1;
    gs->n_density = 1;
    gs->n_featlen = 1;
    gs->n_mbyte = 1;
    gs->fp = NULL;
    
    // Allocate mgau_sl with sufficient size to avoid overflow
    gs->mgau_sl = (int32*)malloc(n * sizeof(int32));
    
    // Initialize pointer arrays to avoid null dereference, though not used in loop
    gs->codeword = (float32**)calloc(1, sizeof(float32*));
    gs->codemap = (uint32***)calloc(1, sizeof(uint32**));
}