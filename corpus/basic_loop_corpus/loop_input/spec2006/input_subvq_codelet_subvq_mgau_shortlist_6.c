#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int int32;

typedef struct {
    int32 r;
    int32 c;
} arraysize_t;

typedef float float32;

typedef double float64;

typedef struct {
    int32 n_gau;
    int32 veclen;
    float32 **mean;
    float32 **var;
    float32 *lrd;
    float64 distfloor;
} vector_gautbl_t;

typedef struct {
    arraysize_t origsize;
    int32 n_sv;
    int32 vqsize;
    int32 **featdim;
    vector_gautbl_t *gautbl;
    int32 ***map;
    float32 *subvec;
    int32 **vqdist;
    int32 *gauscore;
    int32 *mgau_sl;
} subvq_t;

subvq_t *vq;
int32 n = 100000;
int32 *gauscore;
int32 *map;
int32 i;
int32 v;
int32 bv = 0;
int32 *vqdist;
int32 sv_id;

void init_vars() {
    vq = (subvq_t*)calloc(1, sizeof(subvq_t));
    vq->n_sv = 8;
    vq->vqsize = 256;

    gauscore = (int32*)calloc(n, sizeof(int32));

    map = (int32*)malloc(vq->n_sv * n * sizeof(int32));
    for (int i = 0; i < vq->n_sv * n; i++) {
        map[i] = rand() % vq->vqsize;
    }

    vqdist = (int32*)malloc(vq->vqsize * sizeof(int32));
    for (int i = 0; i < vq->vqsize; i++) {
        vqdist[i] = rand() % 100 + 1;
    }

    vq->map = (int32***)malloc(n * sizeof(int32**));
    int32* temp_map_ptr = map;
    for (int i = 0; i < n; i++) {
        vq->map[i] = (int32**)malloc(vq->n_sv * sizeof(int32*));
        for (int j = 0; j < vq->n_sv; j++) {
            vq->map[i][j] = &temp_map_ptr[i * vq->n_sv + j];
        }
    }
}