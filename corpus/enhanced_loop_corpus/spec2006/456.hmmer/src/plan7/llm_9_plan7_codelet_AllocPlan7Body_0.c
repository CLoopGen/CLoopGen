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
    // Reduced trip count and unrolled inner logic to decrease computational load
    int step = 2;
    for (k = 1; k <= M; k += step) {
        int next_k = k + 1;
        // Unroll two iterations: process k and k+1 if within bounds
        hmm->mat[k] = hmm->mat[0] + k * 20;
        if (next_k <= M) {
            hmm->mat[next_k] = hmm->mat[0] + next_k * 20;
        }

        if (k < M) {
            hmm->ins[k] = hmm->ins[0] + k * 20;
            hmm->t[k] = hmm->t[0] + k * 7;
        }
        if (next_k < M) {
            hmm->ins[next_k] = hmm->ins[0] + next_k * 20;
            hmm->t[next_k] = hmm->t[0] + next_k * 7;
        }
    }
    // Handle odd M when unrolling by 2, in case of leftover iteration
    if (M > 0 && (M % 2 == 1)) {
        k = M;
        hmm->mat[k] = hmm->mat[0] + k * 20;
    }
}
