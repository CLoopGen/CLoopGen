#include <stdio.h>
#include <stdlib.h>
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

struct plan7_s *hmm;
int M;
int x;

void init_vars() {
    M = 100000; // Choose M such that total allocation is ~4MB (100000 * 4 bytes per int)

    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    hmm->M = M;

    // Allocate contiguous memory for tsc pointers and the actual data
    hmm->tsc_mem = (int *)calloc(M * 7, sizeof(int));
    if (!hmm->tsc_mem) exit(1);

    hmm->tsc = (int **)calloc(7, sizeof(int *));
    if (!hmm->tsc) exit(1);

    for (int i = 0; i < 7; i++) {
        hmm->tsc[i] = hmm->tsc_mem + i * M;
    }
}

// The loop function will be provided externally, but we define all necessary symbols here