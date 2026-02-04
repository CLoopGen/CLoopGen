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
int *mc;
int *dc;
int *ic;
int *ms;
int *is;
int *mpp;
int *mpc;
int *ip;
int *bp;
int *ep;
int xmb;
int xme;
int *dpp;
int *tpmm;
int *tpmi;
int *tpmd;
int *tpim;
int *tpii;
int *tpdm;
int *tpdd;
int M;

void init_vars() {
    // Set problem size for ~0.01 sec runtime: use L ≈ 5000, M ≈ 200
    L = 5000;
    M = 200;

    // Allocate dsq: sequence of length L+1 (1-indexed)
    dsq = (char*)malloc((L + 1) * sizeof(char));
    for (int idx = 0; idx <= L; idx++) {
        dsq[idx] = (rand() % 4) + 1; // Valid residue codes 1-4
    }

    // Allocate hmm structure
    hmm = (struct plan7_s*)malloc(sizeof(struct plan7_s));
    memset(hmm, 0, sizeof(struct plan7_s));
    hmm->M = M;

    // Initialize xsc: transition scores for begin/end states
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 2; b++) {
            hmm->xsc[a][b] = (a == 0 && b == 0) ? -10 : (rand() % 10 - 15);
        }
    }

    // Allocate and initialize esc (end state scores)
    hmm->esc = (int*)malloc((M + 1) * sizeof(int));
    for (int k = 0; k <= M; k++) {
        hmm->esc[k] = rand() % 20 - 10;
    }

    // Allocate msc and isc (match/insert emission scores per residue)
    hmm->msc = (int**)malloc(5 * sizeof(int*));
    hmm->isc = (int**)malloc(5 * sizeof(int*));
    for (int r = 0; r < 5; r++) {
        hmm->msc[r] = (int*)malloc((M + 1) * sizeof(int));
        hmm->isc[r] = (int*)malloc((M + 1) * sizeof(int));
        for (int k = 0; k <= M; k++) {
            hmm->msc[r][k] = rand() % 20 - 10;
            hmm->isc[r][k] = rand() % 20 - 10;
        }
    }

    // Allocate transition probability arrays (size M)
    tpmm = (int*)malloc(M * sizeof(int));
    tpmi = (int*)malloc(M * sizeof(int));
    tpmd = (int*)malloc(M * sizeof(int));
    tpim = (int*)malloc(M * sizeof(int));
    tpii = (int*)malloc(M * sizeof(int));
    tpdm = (int*)malloc(M * sizeof(int));
    tpdd = (int*)malloc(M * sizeof(int));
    bp = (int*)malloc((M + 1) * sizeof(int));
    for (int k = 0; k <= M; k++) {
        bp[k] = (k == 1) ? 0 : -987654321;
    }
    for (int k = 0; k < M; k++) {
        tpmm[k] = rand() % 20 - 10;
        tpmi[k] = rand() % 20 - 10;
        tpmd[k] = rand() % 20 - 10;
        tpim[k] = rand() % 20 - 10;
        tpii[k] = rand() % 20 - 10;
        tpdm[k] = rand() % 20 - 10;
        tpdd[k] = rand() % 20 - 10;
    }

    // Allocate 2D matrices: xmx, mmx, imx, dmx of size (L+1) x (M+1)
    xmx = (int**)malloc((L + 1) * sizeof(int*));
    mmx = (int**)malloc((L + 1) * sizeof(int*));
    imx = (int**)malloc((L + 1) * sizeof(int*));
    dmx = (int**)malloc((L + 1) * sizeof(int*));

    for (int i = 0; i <= L; i++) {
        xmx[i] = (int*)calloc(5, sizeof(int)); // only 5 special states
        mmx[i] = (int*)malloc((M + 1) * sizeof(int));
        imx[i] = (int*)malloc((M + 1) * sizeof(int));
        dmx[i] = (int*)malloc((M + 1) * sizeof(int));

        for (int k = 0; k <= M; k++) {
            mmx[i][k] = -987654321;
            imx[i][k] = -987654321;
            dmx[i][k] = -987654321;
        }
    }

    // Initialize first row to valid values to start recursion
    for (int k = 0; k <= M; k++) {
        mmx[0][k] = -987654321;
        imx[0][k] = -987654321;
        dmx[0][k] = -987654321;
    }
    xmx[0][0] = 0;
    for (int s = 1; s < 5; s++) {
        xmx[0][s] = -987654321;
    }
}