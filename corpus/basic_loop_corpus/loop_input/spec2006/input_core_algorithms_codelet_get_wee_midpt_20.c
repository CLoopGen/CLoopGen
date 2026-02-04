#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
int k1 = 1;
int k3 = 1000000;
int **mmx;
int **dmx;
int cur = 0;
int k;
int sc;

void init_vars() {
    hmm = (struct plan7_s *)malloc(sizeof(struct plan7_s));
    hmm->M = 1000002;
    hmm->tsc = (int **)malloc(7 * sizeof(int *));
    for (int i = 0; i < 7; i++) {
        hmm->tsc[i] = (int *)calloc(hmm->M, sizeof(int));
    }

    mmx = (int **)malloc(1 * sizeof(int *));
    mmx[0] = (int *)calloc(hmm->M, sizeof(int));

    dmx = (int **)malloc(1 * sizeof(int *));
    dmx[0] = (int *)calloc(hmm->M, sizeof(int));
}

void loop();