#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
float32 *feat;
int32 s = 0;
int32 i;
int32 *featdim; // This was missing in the previous version and caused the link error

void init_vars() {
    // Allocate top-level vq structure
    vq = (subvq_t*)calloc(1, sizeof(subvq_t));
    
    // Set s to a valid index, assume s=0
    s = 0;

    // Define veclen such that total data is ~tens of MB for measurable runtime
    // Target: loop runs ~0.01 sec -> veclen ~ 1M to 10M iterations typical
    int32 veclen = 8000000; // ~8M elements, each iteration does one load/store -> should take ~0.01s

    // Allocate gautbl array with at least s+1 elements
    vq->gautbl = (vector_gautbl_t*)calloc(s + 1, sizeof(vector_gautbl_t));
    vq->gautbl[s].veclen = veclen;

    // Allocate feat array of size at least max(featdim[0..veclen-1])+1
    // We'll set featdim[i] = i for simplicity, so need feat of size veclen
    feat = (float32*)calloc(veclen, sizeof(float32));

    // Allocate and initialize featdim as a flattened 1D array of length veclen
    featdim = (int32*)calloc(veclen, sizeof(int32));
    for (i = 0; i < veclen; i++) {
        featdim[i] = i; // ensure feat[featdim[i]] = feat[i], valid access
    }

    // Allocate subvec array
    vq->subvec = (float32*)calloc(veclen, sizeof(float32));

    // Initialize other required fields to avoid potential issues
    vq->origsize.r = 1;
    vq->origsize.c = 1;
    vq->n_sv = 1;
    vq->vqsize = 1;
    vq->featdim = &featdim; // not used in loop, but initialize consistently
    vq->map = NULL;
    vq->vqdist = NULL;
    vq->gauscore = NULL;
    vq->mgau_sl = NULL;

    vq->gautbl[s].n_gau = 1;
    vq->gautbl[s].mean = NULL;
    vq->gautbl[s].var = NULL;
    vq->gautbl[s].lrd = NULL;
    vq->gautbl[s].distfloor = 0.0;
}