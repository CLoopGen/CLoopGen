#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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

int Alphabet_size = 20;

struct plan9_s *hmm;
struct plan7_s *plan7;
int k;
int x;

void init_vars() {
    Alphabet_size = 20;

    hmm = (struct plan9_s *)malloc(sizeof(struct plan9_s));
    plan7 = (struct plan7_s *)malloc(sizeof(struct plan7_s));

    hmm->M = 5000;
    plan7->M = hmm->M;

    struct basic_state *ins_array = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));
    hmm->ins = ins_array;

    float **ins_2d = (float **)malloc(hmm->M * sizeof(float *));
    for (int i = 1; i < hmm->M; i++) {
        ins_2d[i] = (float *)calloc(Alphabet_size, sizeof(float));
    }
    plan7->ins = ins_2d;

    hmm->mat = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));
    hmm->del = (struct basic_state *)calloc(hmm->M, sizeof(struct basic_state));

    plan7->t = (float **)malloc(hmm->M * sizeof(float *));
    plan7->mat = (float **)malloc(hmm->M * sizeof(float *));
    plan7->tsc = (int **)malloc(hmm->M * sizeof(int *));
    plan7->msc = (int **)malloc(hmm->M * sizeof(int *));
    plan7->isc = (int **)malloc(hmm->M * sizeof(int *));
    plan7->dnam = (int **)malloc(hmm->M * sizeof(int *));
    plan7->dnai = (int **)malloc(hmm->M * sizeof(int *));

    for (int i = 0; i < hmm->M; i++) {
        plan7->t[i] = (float *)calloc(14, sizeof(float));
        plan7->mat[i] = (float *)calloc(20, sizeof(float));
        plan7->tsc[i] = (int *)calloc(14, sizeof(int));
        plan7->msc[i] = (int *)calloc(20, sizeof(int));
        plan7->isc[i] = (int *)calloc(20, sizeof(int));
        plan7->dnam[i] = (int *)calloc(4, sizeof(int));
        plan7->dnai[i] = (int *)calloc(4, sizeof(int));
    }

    plan7->map = (int *)calloc(hmm->M, sizeof(int));
    plan7->tpri = (int *)calloc(hmm->M, sizeof(int));
    plan7->mpri = (int *)calloc(hmm->M, sizeof(int));
    plan7->ipri = (int *)calloc(hmm->M, sizeof(int));

    plan7->begin = (float *)calloc(hmm->M, sizeof(float));
    plan7->end = (float *)calloc(hmm->M, sizeof(float));

    plan7->bsc_mem = (int *)calloc(hmm->M, sizeof(int));
    plan7->esc_mem = (int *)calloc(hmm->M, sizeof(int));
    plan7->tsc_mem = (int *)calloc(hmm->M * 14, sizeof(int));
    plan7->msc_mem = (int *)calloc(hmm->M * 20, sizeof(int));
    plan7->isc_mem = (int *)calloc(hmm->M * 20, sizeof(int));

    plan7->bsc = plan7->bsc_mem;
    plan7->esc = plan7->esc_mem;

    plan7->name = (char *)calloc(64, sizeof(char));
    plan7->acc = (char *)calloc(64, sizeof(char));
    plan7->desc = (char *)calloc(256, sizeof(char));
    plan7->rf = (char *)calloc(64, sizeof(char));
    plan7->cs = (char *)calloc(64, sizeof(char));
    plan7->ca = (char *)calloc(64, sizeof(char));
    plan7->comlog = (char *)calloc(256, sizeof(char));
    plan7->ctime = (char *)calloc(32, sizeof(char));

    hmm->name = (char *)calloc(64, sizeof(char));
    hmm->ref = (char *)calloc(64, sizeof(char));
    hmm->cs = (char *)calloc(64, sizeof(char));
    hmm->xray = (float *)calloc(100, sizeof(float));

    for (int i = 1; i < hmm->M; i++) {
        for (int j = 0; j < Alphabet_size; j++) {
            hmm->ins[i].p[j] = (float)(i * j) / (i + j + 1);
        }
    }
}