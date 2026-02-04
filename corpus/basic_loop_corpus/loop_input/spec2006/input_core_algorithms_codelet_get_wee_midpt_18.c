#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int s3;
int **xmx;
int **mmx;
int **imx;
int **dmx;
int s2;
int cur;
int nxt;
int i;
int k;
int sc;

void init_vars() {
    // Set dimensions to control runtime (~0.01 seconds)
    s2 = 0;
    s3 = 5000;  // ~5k iterations
    k1 = 1;
    k3 = 100;   // ~100 inner loop size

    // Allocate hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = k3;
    hmm->flags = 1;

    // Allocate and initialize xsc: 4x2 array
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            hmm->xsc[i][j] = -1000;
        }
    }
    hmm->xsc[2][1] = -100;
    hmm->xsc[1][0] = -100;
    hmm->xsc[0][0] = -100;
    hmm->xsc[0][1] = -100;
    hmm->xsc[1][1] = -100;
    hmm->xsc[2][0] = -100;

    // Allocate bsc, esc arrays of size k3+2
    hmm->bsc = (int *)calloc(k3 + 2, sizeof(int));
    hmm->esc = (int *)calloc(k3 + 2, sizeof(int));
    hmm->tsc = (int **)calloc(k3 + 2, sizeof(int *));
    for (int i = 0; i <= k3 + 1; ++i) {
        hmm->tsc[i] = (int *)calloc(7, sizeof(int)); // tsc[0..6][k]
        for (int j = 0; j < 7; ++j) {
            hmm->tsc[i][j] = -1000;
        }
    }

    // Initialize msc and isc: [alphabet_size][k3+2], alphabet_size = 128 (ASCII)
    hmm->msc = (int **)calloc(128, sizeof(int *));
    hmm->isc = (int **)calloc(128, sizeof(int *));
    for (int i = 0; i < 128; ++i) {
        hmm->msc[i] = (int *)calloc(k3 + 2, sizeof(int));
        hmm->isc[i] = (int *)calloc(k3 + 2, sizeof(int));
        for (int k = 1; k <= k3; ++k) {
            hmm->msc[i][k] = (i % 256) - 128;
            hmm->isc[i][k] = (i % 256) - 128;
        }
    }

    // Allocate dsq of size s3+1
    dsq = (char *)malloc((s3 + 1) * sizeof(char));
    for (int i = 0; i <= s3; ++i) {
        dsq[i] = (char)(rand() % 20 + 65); // printable ASCII
    }

    // Allocate xmx, mmx, imx, dmx: each is [2][k3+2]
    xmx = (int **)calloc(2, sizeof(int *));
    mmx = (int **)calloc(2, sizeof(int *));
    imx = (int **)calloc(2, sizeof(int *));
    dmx = (int **)calloc(2, sizeof(int *));
    for (int c = 0; c < 2; ++c) {
        xmx[c] = (int *)calloc(k3 + 5, sizeof(int));
        mmx[c] = (int *)calloc(k3 + 5, sizeof(int));
        imx[c] = (int *)calloc(k3 + 5, sizeof(int));
        dmx[c] = (int *)calloc(k3 + 5, sizeof(int));
    }

    // Initialize cur/nxt indices
    cur = 0;
    nxt = 1;

    // Initialize scalar variables
    i = 0;
    k = 0;
    sc = 0;
}