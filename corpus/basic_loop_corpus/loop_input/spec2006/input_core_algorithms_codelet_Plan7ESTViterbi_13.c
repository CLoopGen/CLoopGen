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
    // Allocate and initialize hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = 2000;  // Set M so that the loop runs over 2001 elements

    // Allocate memory for mmx, imx, dmx: each is a 2D array with dimensions [1][M+1]
    mmx = (int **)calloc(1, sizeof(int*));
    imx = (int **)calloc(1, sizeof(int*));
    dmx = (int **)calloc(1, sizeof(int*));

    mmx[0] = (int *)malloc((hmm->M + 1) * sizeof(int));
    imx[0] = (int *)malloc((hmm->M + 1) * sizeof(int));
    dmx[0] = (int *)malloc((hmm->M + 1) * sizeof(int));
}