#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
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
float *mp;
float *ip;
int nmat;
int ndel;
int nins;
int k;

void init_vars() {
    // Allocate and initialize hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    
    // Set M to ~50000 to achieve desired runtime (~0.01 sec)
    // This value is chosen so that the loop runs enough iterations to take ~10ms
    // assuming moderate CPU speed and simple arithmetic per iteration.
    hmm->M = 50000;

    // Allocate mp and ip arrays of size M+1 (indexed from 1 to M)
    mp = (float *)calloc(hmm->M + 1, sizeof(float));
    ip = (float *)calloc(hmm->M + 1, sizeof(float));

    // Initialize t as array of float pointers: t[M+1][5] -> indices [1..M][0..4]
    hmm->t = (float **)calloc(hmm->M + 1, sizeof(float*));
    for (int i = 1; i <= hmm->M; i++) {
        hmm->t[i] = (float *)calloc(5, sizeof(float));
        // Set t[k][4] to a value less than 1.0 so that division in loop is safe
        hmm->t[i][4] = 0.8f; // ensures (1.F - t[k][4]) = 0.2 -> 1/0.2 = 5
    }

    // Initialize other fields if needed (not accessed in loop, but avoid dangling pointers)
    hmm->map = NULL;
    hmm->tpri = NULL;
    hmm->mpri = NULL;
    hmm->ipri = NULL;
    hmm->mat = NULL;
    hmm->ins = NULL;
    hmm->tsc = NULL;
    hmm->msc = NULL;
    hmm->isc = NULL;
    hmm->bsc = NULL;
    hmm->esc = NULL;
    hmm->tsc_mem = NULL;
    hmm->msc_mem = NULL;
    hmm->isc_mem = NULL;
    hmm->bsc_mem = NULL;
    hmm->esc_mem = NULL;
    hmm->dnam = NULL;
    hmm->dnai = NULL;
    hmm->dna2 = 0;
    hmm->dna4 = 0;
    hmm->mu = 0.0f;
    hmm->lambda = 0.0f;
    hmm->flags = 0;
    hmm->ga1 = 0.0f;
    hmm->ga2 = 0.0f;
    hmm->tc1 = 0.0f;
    hmm->tc2 = 0.0f;
    hmm->nc1 = 0.0f;
    hmm->nc2 = 0.0f;
    hmm->nseq = 0;
    hmm->checksum = 0;
    hmm->tbd1 = 0.0f;
    hmm->p1 = 0.0f;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            hmm->xt[i][j] = 0.0f;
            hmm->xsc[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        hmm->null[i] = 0.0f;
    }

    // Initialize mp and ip with random-like values around 0.5 threshold
    for (int i = 1; i <= hmm->M; i++) {
        mp[i] = (float)rand() / RAND_MAX;  // 0.0 to 1.0
        ip[i] = (float)rand() / RAND_MAX;
    }

    // Initialize counters
    nmat = 0;
    ndel = 0;
    nins = 0;
}