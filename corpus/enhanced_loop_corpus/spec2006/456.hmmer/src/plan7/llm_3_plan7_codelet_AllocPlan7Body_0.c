#include <stdio.h>

#include <inttypes.h>

struct plan7_s {
    char *name;
    char *acc;
    char *desc;
    char *rf;
    char *cs;
    char *ca;
    char *comlog;
    int nseq;
    char *ctime;
    int *map;
    int checksum;
    int *tpri;
    int *mpri;
    int *ipri;
    float ga1;
    float ga2;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    int M;
    float **t;
    float **mat;
    float **ins;
    float tbd1;
    float xt[4][2];
    float *begin;
    float *end;
    float null[20];
    float p1;
    int **tsc;
    int **msc;
    int **isc;
    int xsc[4][2];
    int *bsc;
    int *esc;
    int *tsc_mem;
    int *msc_mem;
    int *isc_mem;
    int *bsc_mem;
    int *esc_mem;
    int **dnam;
    int **dnai;
    int dna2;
    int dna4;
    float mu;
    float lambda;
    int flags;
};


extern struct plan7_s *hmm;
extern int M;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern using a fixed stride multiplier to simulate non-unit strides
    // This variant simulates a scenario where elements are accessed with a gap (stride > 1)
    const int stride_factor = 2;
    int effective_k;

    for (k = 1; k <= M; k++) {
        effective_k = k * stride_factor; // Simulate strided iteration

        hmm->mat[effective_k] = hmm->mat[0] + effective_k * 20;

        if (effective_k < M) {
            hmm->ins[effective_k] = hmm->ins[0] + effective_k * 20;
            hmm->t[effective_k]   = hmm->t[0]   + effective_k * 7;
        }
    }
}
