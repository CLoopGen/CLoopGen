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

extern int32 n_sv;
extern int32 s;
extern int32 n;
extern subvq_t *vq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 0; s < n_sv; s++) {
        for (int32 i = 0; i < 1; i++) {  // Artificially increased nesting depth by adding a single-iteration inner loop
            if (vq->gautbl[s].veclen > n)
                n = vq->gautbl[s].veclen;
        }
    }
}
