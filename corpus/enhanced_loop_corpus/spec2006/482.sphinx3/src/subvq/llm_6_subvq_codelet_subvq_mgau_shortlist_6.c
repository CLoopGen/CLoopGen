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
extern int32 n;
extern int32 *gauscore;
extern int32 *map;
extern int32 i;
extern int32 v;
extern int32 bv;
extern int32 *vqdist;
extern int32 sv_id;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_gauscore;
    for (i = 0; i < n; i++) {
        temp_gauscore = 0;
        for (sv_id = 0; sv_id < vq->n_sv; sv_id++) {
            temp_gauscore += vqdist[map[i * vq->n_sv + sv_id]];
        }
        gauscore[i] = temp_gauscore;
        if (bv < temp_gauscore)
            bv = temp_gauscore;
    }
}
