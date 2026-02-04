#include <stdio.h>

#include <inttypes.h>

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

extern subvq_t *vq;
extern float32 *feat;
extern int32 s;
extern int32 i;
extern int32 *featdim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 i1;
    int32 chunk_size = 4;
    int32 len = vq->gautbl[s].veclen;
    int32 remainder = len % chunk_size;

    // Unrolled loop with depth increased via manual unrolling
    for (i1 = 0; i1 < len - remainder; i1 += chunk_size) {
        vq->subvec[i1]     = feat[featdim[i1]];
        vq->subvec[i1 + 1] = feat[featdim[i1 + 1]];
        vq->subvec[i1 + 2] = feat[featdim[i1 + 2]];
        vq->subvec[i1 + 3] = feat[featdim[i1 + 3]];
    }

    // Handle remaining elements
    for (i1 = len - remainder; i1 < len; i1++) {
        vq->subvec[i1] = feat[featdim[i1]];
    }
}
