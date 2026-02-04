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
int M = 10000;  // Sufficiently large to ensure ~0.01s runtime with data size
int x;

void init_vars() {
    // Allocate hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    // Set M to control data size
    hmm->M = M;

    // Allocate msc and isc arrays of pointers (24 rows each)
    hmm->msc = (int **)calloc(24, sizeof(int *));
    hmm->isc = (int **)calloc(24, sizeof(int *));
    if (!hmm->msc || !hmm->isc) exit(1);

    // Allocate memory pools for msc[0] and isc[0]
    hmm->msc_mem = (int *)calloc(24 * (M + 1), sizeof(int));
    hmm->isc_mem = (int *)calloc(24 * M, sizeof(int));
    if (!hmm->msc_mem || !hmm->isc_mem) exit(1);

    // Initialize base pointers
    hmm->msc[0] = hmm->msc_mem;
    hmm->isc[0] = hmm->isc_mem;
}