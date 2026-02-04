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
float basep;
int k;

void init_vars() {
    // Allocate hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) return;

    // Set M to a value that makes the loop run ~0.01 seconds
    // Assume modern CPU does ~1e9 iterations/sec -> 1e7 iterations in 0.01s
    // But we want memory size around 1MB-256MB; end[] is float array of size M
    // Each float is 4 bytes. To get ~100MB: M ~ 25e6
    hmm->M = 25000000;  // 25 million elements -> ~100MB for float array

    // Allocate and initialize end array
    hmm->end = (float *)calloc(hmm->M, sizeof(float));
    if (!hmm->end) return;

    // Initialize other required fields to avoid crashes
    hmm->begin = (float *)calloc(hmm->M, sizeof(float));
    if (!hmm->begin) return;

    // Initialize basep to a reasonable value
    basep = 0.1f;

    // Initialize any other pointers that might be accessed indirectly
    hmm->name = NULL;
    hmm->acc = NULL;
    hmm->desc = NULL;
    hmm->rf = NULL;
    hmm->cs = NULL;
    hmm->ca = NULL;
    hmm->comlog = NULL;
    hmm->ctime = NULL;
    hmm->map = NULL;
    hmm->tpri = NULL;
    hmm->mpri = NULL;
    hmm->ipri = NULL;
    hmm->t = NULL;
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

    // Initialize scalar values
    hmm->checksum = 0;
    hmm->ga1 = 0.0f;
    hmm->ga2 = 0.0f;
    hmm->tc1 = 0.0f;
    hmm->tc2 = 0.0f;
    hmm->nc1 = 0.0f;
    hmm->nc2 = 0.0f;
    hmm->tbd1 = 0.0f;
    hmm->p1 = 0.0f;
    hmm->dna2 = 0;
    hmm->dna4 = 0;
    hmm->mu = 0.0f;
    hmm->lambda = 0.0f;
    hmm->flags = 0;

    // Zero out arrays
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            hmm->xt[i][j] = 0.0f;
            hmm->xsc[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        hmm->null[i] = 0.0f;
    }
}