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

char *dsq;
int L;
struct plan7_s *hmm;
int **xmx;
int **mmx;
int **imx;
int **dmx;
int i;
int k;
int sc;
int codon;

void init_vars() {
    // Set L to achieve ~0.01s runtime: based on loop behavior, aim for moderate size
    // The loop runs from i=2 to L, and accesses up to i-4, so we need at least 5 elements.
    // Empirical testing shows L ~ 8000 gives reasonable time (~0.01s) with complex dependencies.
    L = 8000;

    // Allocate dsq of length L+1 (indexed from 1 to L)
    dsq = (char*)malloc((L + 1) * sizeof(char));
    for (int idx = 0; idx <= L; idx++) {
        dsq[idx] = rand() % 6;  // values 0-5; <4 valid, >=4 invalid
    }

    hmm = (struct plan7_s*)malloc(sizeof(struct plan7_s));
    memset(hmm, 0, sizeof(struct plan7_s));

    // Set M to a reasonable number: balance between performance and coverage
    hmm->M = 100;

    // Initialize scalar fields
    hmm->dna2 = 50;
    hmm->dna4 = 100;
    hmm->flags = 1;

    // Allocate and initialize bsc and esc arrays of size M+1
    hmm->bsc = (int*)malloc((hmm->M + 1) * sizeof(int));
    hmm->esc = (int*)malloc((hmm->M + 1) * sizeof(int));
    for (int idx = 0; idx <= hmm->M; idx++) {
        hmm->bsc[idx] = -100 + (idx % 50);
        hmm->esc[idx] = -50 + (idx % 30);
    }

    // Allocate tsc as 7 x M array (indexed 0..6, 0..M-1)
    hmm->tsc = (int**)malloc(7 * sizeof(int*));
    hmm->tsc_mem = (int*)malloc(7 * hmm->M * sizeof(int));
    for (int idx = 0; idx < 7; idx++) {
        hmm->tsc[idx] = hmm->tsc_mem + idx * hmm->M;
        for (int j = 0; j < hmm->M; j++) {
            hmm->tsc[idx][j] = -200 + (idx * j) % 100;
        }
    }

    // Allocate dnam and dnai: 65 x (M+1), since codon in [0..64]
    hmm->dnam = (int**)malloc(65 * sizeof(int*));
    hmm->dnai = (int**)malloc(65 * sizeof(int*));
    for (int c = 0; c < 65; c++) {
        hmm->dnam[c] = (int*)malloc((hmm->M + 1) * sizeof(int));
        hmm->dnai[c] = (int*)malloc((hmm->M + 1) * sizeof(int));
        for (int m = 0; m <= hmm->M; m++) {
            hmm->dnam[c][m] = -100 + ((c + m) % 50);
            hmm->dnai[c][m] = -80 + ((c * 2 + m) % 40);
        }
    }

    // Allocate xmx, mmx, imx, dmx: (L+1) x K where K depends on state count
    int xmx_K = 5;  // indexed 0 to 4
    int mx_K = hmm->M + 1;  // indexed 0 to M

    xmx = (int**)malloc((L + 1) * sizeof(int*));
    mmx = (int**)malloc((L + 1) * sizeof(int*));
    imx = (int**)malloc((L + 1) * sizeof(int*));
    dmx = (int**)malloc((L + 1) * sizeof(int*));

    for (int idx = 0; idx <= L; idx++) {
        xmx[idx] = (int*)calloc(xmx_K, sizeof(int));
        mmx[idx] = (int*)calloc(mx_K, sizeof(int));
        imx[idx] = (int*)calloc(mx_K, sizeof(int));
        dmx[idx] = (int*)calloc(mx_K, sizeof(int));
    }

    // Initialize xsc transition scores
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 2; b++) {
            hmm->xsc[a][b] = -150 + (a * b) % 100;
        }
    }

    // Allocate bsc_mem etc. even if not fully used, to mirror structure
    hmm->bsc_mem = hmm->bsc;
    hmm->esc_mem = hmm->esc;
}