#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

struct plan7_s *hmm;
float *fmp;
float *fip;
float *fdp;
int k;

void init_vars() {
    // Set model size to achieve desired runtime (~0.01 seconds)
    // Based on typical performance, M around 10000-20000 gives appropriate timing
    int M = 16000;
    
    // Allocate and initialize hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = M;
    
    // Allocate and initialize t matrix: [0..M-1][7] (we use indices 0,1,2,5,6)
    hmm->t = (float **)calloc(M, sizeof(float *));
    for (int i = 0; i < M; i++) {
        hmm->t[i] = (float *)calloc(7, sizeof(float));
        // Initialize transition probabilities
        hmm->t[i][0] = 0.8f;
        hmm->t[i][1] = 0.1f;
        hmm->t[i][2] = 0.05f;
        hmm->t[i][5] = 0.1f;
        hmm->t[i][6] = 0.85f;
    }
    
    // Allocate and initialize begin scores
    hmm->begin = (float *)calloc(M + 1, sizeof(float));
    for (int i = 0; i <= M; i++) {
        hmm->begin[i] = 0.1f;
    }
    
    // Allocate fmp, fip, fdp arrays of size M+1 (indexed 0..M)
    fmp = (float *)calloc(M + 1, sizeof(float));
    fip = (float *)calloc(M + 1, sizeof(float));
    fdp = (float *)calloc(M + 1, sizeof(float));
    
    // Initialize boundary conditions
    fmp[0] = 1.0f;
    fip[0] = 0.0f;
    fdp[0] = 0.0f;
    
    // Initialize other fields that might be accessed
    hmm->end = (float *)calloc(M + 1, sizeof(float));
    for (int i = 0; i <= M; i++) {
        hmm->end[i] = 0.1f;
    }
    
    // Initialize some xt values
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            hmm->xt[i][j] = 0.5f;
        }
    }
    
    // Initialize xsc
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            hmm->xsc[i][j] = 100;
        }
    }
    
    // Set scalar values
    hmm->dna2 = 4;
    hmm->dna4 = 6;
    hmm->mu = 0.01f;
    hmm->lambda = 0.02f;
    hmm->flags = 1;
    hmm->tbd1 = 0.5f;
    hmm->p1 = 0.3f;
    
    // Initialize null array
    for (int i = 0; i < 20; i++) {
        hmm->null[i] = 0.05f;
    }
    
    // Initialize other pointers to valid memory (though not used in loop)
    hmm->tsc_mem = (int *)calloc(100, sizeof(int));
    hmm->msc_mem = (int *)calloc(100, sizeof(int));
    hmm->isc_mem = (int *)calloc(100, sizeof(int));
    hmm->bsc_mem = (int *)calloc(100, sizeof(int));
    hmm->esc_mem = (int *)calloc(100, sizeof(int));
    
    hmm->bsc = hmm->bsc_mem;
    hmm->esc = hmm->esc_mem;
}