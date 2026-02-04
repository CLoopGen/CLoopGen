#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef int int32;
typedef float float32;
typedef double float64;

typedef struct {
    int32 r;
    int32 c;
} arraysize_t;

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
int32 r;
int32 c;
int32 s;

void init_vars() {
    // Allocate and initialize vq structure
    vq = (subvq_t*)calloc(1, sizeof(subvq_t));
    
    // Set dimensions to control data size (~100ms runtime target)
    // Aim for moderate sizes: rows ~2000, cols ~50, n_sv ~8 -> total map entries ~800k
    vq->origsize.r = 2000;
    vq->origsize.c = 50;
    vq->n_sv = 8;
    vq->vqsize = 256;  // typical codebook size

    // Allocate map: [r][c][s] = vq->map[r][c][s]
    vq->map = (int32***)calloc(vq->origsize.r, sizeof(int32**));
    for (int i = 0; i < vq->origsize.r; i++) {
        vq->map[i] = (int32**)calloc(vq->origsize.c, sizeof(int32*));
        for (int j = 0; j < vq->origsize.c; j++) {
            vq->map[i][j] = (int32*)malloc(vq->n_sv * sizeof(int32));
            // Initialize with valid indices, some negative to terminate inner loop early sometimes
            for (int k = 0; k < vq->n_sv; k++) {
                // Spread initial values between 0 and 255 to be within vqsize range
                vq->map[i][j][k] = rand() % 256;  // 0 to 255
            }
            // Ensure condition (vq->map[r][c][0] >= 0) fails on some entries to simulate early exit
            if (j == vq->origsize.c - 1) {
                vq->map[i][j][0] = -1;  // force exit on last column
            }
        }
    }

    // Allocate and initialize other required fields to avoid null pointer dereference
    vq->featdim = (int32**)calloc(vq->origsize.r, sizeof(int32*));
    for (int i = 0; i < vq->origsize.r; i++) {
        vq->featdim[i] = (int32*)calloc(vq->origsize.c, sizeof(int32));
        for (int j = 0; j < vq->origsize.c; j++) {
            vq->featdim[i][j] = 1;
        }
    }

    vq->gautbl = (vector_gautbl_t*)calloc(1, sizeof(vector_gautbl_t));
    vq->gautbl->n_gau = vq->vqsize * vq->n_sv;
    vq->gautbl->veclen = 16;
    vq->gautbl->distfloor = 1e-6;

    // Allocate subvec: size proportional to total feature vectors
    vq->subvec = (float32*)calloc(vq->origsize.r * vq->origsize.c * vq->n_sv, sizeof(float32));
    
    vq->vqdist = (int32**)calloc(vq->origsize.r, sizeof(int32*));
    for (int i = 0; i < vq->origsize.r; i++) {
        vq->vqdist[i] = (int32*)calloc(vq->origsize.c, sizeof(int32));
    }

    vq->gauscore = (int32*)calloc(vq->gautbl->n_gau, sizeof(int32));
    vq->mgau_sl = (int32*)calloc(vq->origsize.r, sizeof(int32));

    // Initialize gautbl->mean and gautbl->var if needed (not accessed in loop, but allocate to be safe)
    vq->gautbl->mean = (float32**)calloc(vq->gautbl->n_gau, sizeof(float32*));
    vq->gautbl->var = (float32**)calloc(vq->gautbl->n_gau, sizeof(float32*));
    for (int i = 0; i < vq->gautbl->n_gau; i++) {
        vq->gautbl->mean[i] = (float32*)calloc(vq->gautbl->veclen, sizeof(float32));
        vq->gautbl->var[i] = (float32*)calloc(vq->gautbl->veclen, sizeof(float32));
        for (int j = 0; j < vq->gautbl->veclen; j++) {
            vq->gautbl->mean[i][j] = 0.5f;
            vq->gautbl->var[i][j] = 1.0f;
        }
    }

    vq->gautbl->lrd = (float32*)calloc(vq->gautbl->n_gau, sizeof(float32));
    for (int i = 0; i < vq->gautbl->n_gau; i++) {
        vq->gautbl->lrd[i] = -10.0f;
    }

    // Initialize scalar loop counters
    r = 0;
    c = 0;
    s = 0;
}