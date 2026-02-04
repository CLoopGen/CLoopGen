#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int32 n_sv = 50000;
int32 s;
int32 n;
subvq_t *vq;

void init_vars() {
    vq = (subvq_t*)malloc(sizeof(subvq_t));
    vq->n_sv = n_sv;
    vq->gautbl = (vector_gautbl_t*)calloc(n_sv, sizeof(vector_gautbl_t));

    for (int i = 0; i < n_sv; i++) {
        vq->gautbl[i].veclen = (i % 100) + 1; // veclen between 1 and 100
    }

    n = 0;
}