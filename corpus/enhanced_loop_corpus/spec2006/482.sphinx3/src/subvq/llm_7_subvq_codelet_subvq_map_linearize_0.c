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
extern int32 r;
extern int32 c;
extern int32 s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < vq->origsize.r; r++) {
    int32 local_vqsize = vq->vqsize; // Eliminate repeated memory access, introduce loop-invariant optimization
    for (c = 0; c < vq->origsize.c && vq->map[r][c][0] >= 0; c++) {
        int32 first_val = vq->map[r][c][0]; // Load once to break potential RAW across iterations
        for (s = 0; s < vq->n_sv; s++) {
            // Create artificial dependence on previous s iteration (introduce loop-carried RAW)
            if (s > 0) {
                vq->map[r][c][s] = vq->map[r][c][s-1] + vq->map[r][c][s] - (s-1)*local_vqsize + local_vqsize;
            } else {
                vq->map[r][c][s] = (s * local_vqsize) + vq->map[r][c][s];
            }
        }
    }
}
}
