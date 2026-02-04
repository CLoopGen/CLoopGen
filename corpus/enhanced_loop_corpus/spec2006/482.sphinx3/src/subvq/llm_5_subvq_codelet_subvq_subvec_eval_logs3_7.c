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
    for (i = 0; i < vq->gautbl[s].veclen; i++) {
        if (featdim[i] < 0) {
            continue;
        }
        vq->subvec[i] = feat[featdim[i]];
    }
}
