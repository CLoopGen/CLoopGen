#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct basic_state {
    float t[3];
    float p[20];
};

struct plan9_s {
    int M;
    struct basic_state *ins;
    struct basic_state *mat;
    struct basic_state *del;
    float null[20];
    char *name;
    char *ref;
    char *cs;
    float *xray;
    int flags;
};

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

struct plan9_s *hmm;
struct plan7_s *plan7;
int k;

void init_vars() {
    hmm = (struct plan9_s *)malloc(sizeof(struct plan9_s));
    plan7 = (struct plan7_s *)malloc(sizeof(struct plan7_s));

    hmm->M = 10000000; // ~10M iterations to target ~0.01 sec runtime

    // Allocate arrays for hmm
    hmm->ins = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));
    hmm->mat = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));
    hmm->del = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));
    hmm->name = (char *)calloc(1, 1);
    hmm->ref = (char *)calloc(1, 1);
    hmm->cs = (char *)calloc(1, 1);
    hmm->xray = (float *)calloc(20, sizeof(float));

    // Initialize plan7
    plan7->M = hmm->M;
    plan7->t = (float **)malloc(plan7->M * sizeof(float *));
    for (int i = 0; i < plan7->M; i++) {
        plan7->t[i] = (float *)calloc(7, sizeof(float)); // indices 0-6 used
    }
    plan7->mat = (float **)malloc(plan7->M * sizeof(float *));
    plan7->ins = (float **)malloc(plan7->M * sizeof(float *));
    for (int i = 0; i < plan7->M; i++) {
        plan7->mat[i] = (float *)calloc(1, sizeof(float));
        plan7->ins[i] = (float *)calloc(1, sizeof(float));
    }

    // Initialize other required pointers to valid memory
    plan7->name = (char *)calloc(1, 1);
    plan7->acc = (char *)calloc(1, 1);
    plan7->desc = (char *)calloc(1, 1);
    plan7->rf = (char *)calloc(1, 1);
    plan7->cs = (char *)calloc(1, 1);
    plan7->ca = (char *)calloc(1, 1);
    plan7->comlog = (char *)calloc(1, 1);
    plan7->ctime = (char *)calloc(1, 1);
    plan7->map = (int *)calloc(1, sizeof(int));
    plan7->tpri = (int *)calloc(1, sizeof(int));
    plan7->mpri = (int *)calloc(1, sizeof(int));
    plan7->ipri = (int *)calloc(1, sizeof(int));
    plan7->begin = (float *)calloc(1, sizeof(float));
    plan7->end = (float *)calloc(1, sizeof(float));
    plan7->tsc = (int **)malloc(1 * sizeof(int *));
    plan7->msc = (int **)malloc(1 * sizeof(int *));
    plan7->isc = (int **)malloc(1 * sizeof(int *));
    plan7->tsc_mem = (int *)calloc(1, sizeof(int));
    plan7->msc_mem = (int *)calloc(1, sizeof(int));
    plan7->isc_mem = (int *)calloc(1, sizeof(int));
    plan7->bsc_mem = (int *)calloc(1, sizeof(int));
    plan7->esc_mem = (int *)calloc(1, sizeof(int));
    plan7->bsc = (int *)calloc(1, sizeof(int));
    plan7->esc = (int *)calloc(1, sizeof(int));
    plan7->dnam = (int **)malloc(1 * sizeof(int *));
    plan7->dnai = (int **)malloc(1 * sizeof(int *));
}