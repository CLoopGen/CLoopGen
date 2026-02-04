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
int **mmx;
int **imx;
int **dmx;
int k;

void init_vars() {
    hmm = (struct plan7_s *)malloc(sizeof(struct plan7_s));
    hmm->M = 20000;

    int M_plus_one = hmm->M + 1;

    mmx = (int **)malloc(1 * sizeof(int *));
    imx = (int **)malloc(1 * sizeof(int *));
    dmx = (int **)malloc(1 * sizeof(int *));

    mmx[0] = (int *)malloc(M_plus_one * sizeof(int));
    imx[0] = (int *)malloc(M_plus_one * sizeof(int));
    dmx[0] = (int *)malloc(M_plus_one * sizeof(int));

    for (int i = 0; i <= hmm->M; i++) {
        mmx[0][i] = -987654321;
        imx[0][i] = -987654321;
        dmx[0][i] = -987654321;
    }
}