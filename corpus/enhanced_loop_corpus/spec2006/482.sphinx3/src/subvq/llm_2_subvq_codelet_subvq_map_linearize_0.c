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
    // Variant 1: Change memory access pattern to strided access by unrolling and accessing every second element
    // This modifies the inner loop to process elements with a stride of 2 for indirect array 'map'
    for (r = 0; r < vq->origsize.r; r++) {
        for (c = 0; (c + 1 < vq->origsize.c) && (vq->map[r][c][0] >= 0 || vq->map[r][c+1][0] >= 0); c += 2) {
            if (vq->map[r][c][0] >= 0) {
                for (s = 0; s < vq->n_sv; s++)
                    vq->map[r][c][s] = (s * vq->vqsize) + vq->map[r][c][s];
            }
            if (c + 1 < vq->origsize.c && vq->map[r][c+1][0] >= 0) {
                for (s = 0; s < vq->n_sv; s++)
                    vq->map[r][c+1][s] = (s * vq->vqsize) + vq->map[r][c+1][s];
            }
        }
        // Handle odd-sized rows
        if (c < vq->origsize.c && vq->map[r][c][0] >= 0) {
            for (s = 0; s < vq->n_sv; s++)
                vq->map[r][c][s] = (s * vq->vqsize) + vq->map[r][c][s];
        }
    }
}
