#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char *dsq;
int k1;
int k3;
int **xmx;
int **mmx;
int **imx;
int **dmx;
int s2;
int cur;
int prv;
int i;
int k;
int sc;
int start;

void init_vars() {
    // Allocate and initialize hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = 100;
    k1 = 1;
    k3 = hmm->M;
    s2 = 50000;
    start = 0;

    // Allocate dsq with size s2+1
    dsq = (char *)malloc((s2 + 1) * sizeof(char));
    for (int idx = 0; idx <= s2; idx++) {
        dsq[idx] = rand() % 4 + 1; // valid indices 1-4
    }

    // Allocate 2D matrices with 2 rows (cur/prv) and M+1 columns
    mmx = (int **)calloc(2, sizeof(int *));
    imx = (int **)calloc(2, sizeof(int *));
    dmx = (int **)calloc(2, sizeof(int *));
    xmx = (int **)calloc(2, sizeof(int *));
    
    for (int c = 0; c < 2; c++) {
        mmx[c] = (int *)calloc(hmm->M + 1, sizeof(int));
        imx[c] = (int *)calloc(hmm->M + 1, sizeof(int));
        dmx[c] = (int *)calloc(hmm->M + 1, sizeof(int));
        xmx[c] = (int *)calloc(5, sizeof(int)); // xmx has fixed second dimension of at least 5
    }

    // Initialize xsc in hmm
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 2; c++) {
            hmm->xsc[r][c] = -987654321;
        }
    }
    hmm->xsc[0][1] = 100;
    hmm->xsc[0][0] = 100;
    hmm->xsc[2][1] = 100;
    hmm->xsc[1][0] = 100;

    // Allocate and initialize bsc and esc arrays
    hmm->bsc = (int *)calloc(hmm->M + 1, sizeof(int));
    hmm->esc = (int *)calloc(hmm->M + 1, sizeof(int));
    for (int idx = 0; idx <= hmm->M; idx++) {
        hmm->bsc[idx] = 100;
        hmm->esc[idx] = 50;
    }

    // Allocate tsc, msc, isc as 7x(M+1) and 5x(M+1) respectively
    hmm->tsc = (int **)calloc(7, sizeof(int *));
    hmm->msc = (int **)calloc(5, sizeof(int *));
    hmm->isc = (int **)calloc(5, sizeof(int *));
    
    for (int r = 0; r < 7; r++) {
        hmm->tsc[r] = (int *)calloc(hmm->M + 1, sizeof(int));
        for (int c = 0; c <= hmm->M; c++) {
            hmm->tsc[r][c] = (r == 0 || r == 3 || r == 5 || r == 6) ? 80 : 90;
        }
    }

    for (int r = 0; r < 5; r++) {
        hmm->msc[r] = (int *)calloc(hmm->M + 1, sizeof(int));
        hmm->isc[r] = (int *)calloc(hmm->M + 1, sizeof(int));
        for (int c = 0; c <= hmm->M; c++) {
            hmm->msc[r][c] = (r >= 1 && r <= 4) ? 75 : -987654321;
            hmm->isc[r][c] = (r >= 1 && r <= 4) ? 70 : -987654321;
        }
    }

    // Initialize first row of xmx
    xmx[0][0] = 0;
    xmx[0][1] = 0;
    xmx[0][2] = 0;
    xmx[0][4] = 0;
}