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
int **dmx;
int **imx;
int **xtr;
int **mtr;
int **dtr;
int **itr;
int *btr;
int *etr;
int sc;
int i;
int k;
int cur;
int prv;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, L around 5000-10000 gives reasonable timing
    L = 8000;
    
    // Allocate dsq of length L+1 (1-indexed usage)
    dsq = (char*)malloc((L + 1) * sizeof(char));
    for (int idx = 1; idx <= L; idx++) {
        dsq[idx] = (char)(rand() % 4 + 1); // values 1-4 as commonly used in sequence analysis
    }

    // Allocate HMM structure
    hmm = (struct plan7_s*)malloc(sizeof(struct plan7_s));
    memset(hmm, 0, sizeof(struct plan7_s));
    
    // Set M to a reasonable value (~100-200 typical for HMM profiles)
    hmm->M = 150;
    
    // Initialize xsc: transition scores between states
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 2; b++) {
            hmm->xsc[a][b] = -987654321;
        }
    }
    hmm->xsc[0][0] = hmm->xsc[0][1] = -100;
    hmm->xsc[1][0] = hmm->xsc[1][1] = -100;
    hmm->xsc[2][0] = hmm->xsc[2][1] = -100;
    hmm->xsc[3][0] = hmm->xsc[3][1] = -100;
    
    // Allocate and initialize bsc, esc arrays
    hmm->bsc = (int*)malloc((hmm->M + 1) * sizeof(int));
    hmm->esc = (int*)malloc((hmm->M + 1) * sizeof(int));
    for (k = 1; k <= hmm->M; k++) {
        hmm->bsc[k] = -100;
        hmm->esc[k] = -100;
    }

    // Allocate tsc: transition score matrix [7][M] (indexed up to 6)
    hmm->tsc = (int**)malloc(7 * sizeof(int*));
    for (int a = 0; a < 7; a++) {
        hmm->tsc[a] = (int*)malloc(hmm->M * sizeof(int));
        for (int b = 0; b < hmm->M; b++) {
            hmm->tsc[a][b] = -100;
        }
    }

    // Allocate msc: match state emission scores [5][M+1]
    hmm->msc = (int**)malloc(5 * sizeof(int*));
    for (int a = 0; a < 5; a++) {
        hmm->msc[a] = (int*)malloc((hmm->M + 1) * sizeof(int));
        for (int b = 1; b <= hmm->M; b++) {
            hmm->msc[a][b] = (a == 0 || b == 0) ? -987654321 : rand() % 200 - 100;
        }
    }

    // Allocate isc: insert state emission scores [5][M+1]
    hmm->isc = (int**)malloc(5 * sizeof(int*));
    for (int a = 0; a < 5; a++) {
        hmm->isc[a] = (int*)malloc((hmm->M + 1) * sizeof(int));
        for (int b = 1; b <= hmm->M; b++) {
            hmm->isc[a][b] = (a == 0 || b == 0) ? -987654321 : rand() % 200 - 100;
        }
    }

    // Allocate dynamic programming matrices with two rows (current and previous)
    xmx = (int**)malloc(2 * sizeof(int*));
    mmx = (int**)malloc(2 * sizeof(int*));
    dmx = (int**)malloc(2 * sizeof(int*));
    imx = (int**)malloc(2 * sizeof(int*));
    xtr = (int**)malloc(2 * sizeof(int*));
    mtr = (int**)malloc(2 * sizeof(int*));
    dtr = (int**)malloc(2 * sizeof(int*));
    itr = (int**)malloc(2 * sizeof(int*));

    for (int row = 0; row < 2; row++) {
        xmx[row] = (int*)calloc(5, sizeof(int)); // indices 0-4
        mmx[row] = (int*)calloc((hmm->M + 1), sizeof(int));
        dmx[row] = (int*)calloc((hmm->M + 1), sizeof(int));
        imx[row] = (int*)calloc((hmm->M + 1), sizeof(int));
        xtr[row] = (int*)calloc(5, sizeof(int));
        mtr[row] = (int*)calloc((hmm->M + 1), sizeof(int));
        dtr[row] = (int*)calloc((hmm->M + 1), sizeof(int));
        itr[row] = (int*)calloc((hmm->M + 1), sizeof(int));
    }

    // Allocate traceback vectors
    btr = (int*)malloc((L + 1) * sizeof(int));
    etr = (int*)malloc((L + 1) * sizeof(int));
    for (int idx = 0; idx <= L; idx++) {
        btr[idx] = etr[idx] = -1;
    }

    // Initialize all DP cells to very low score initially
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col <= 4; col++) {
            xmx[row][col] = -987654321;
        }
        for (int col = 0; col <= hmm->M; col++) {
            mmx[row][col] = dmx[row][col] = imx[row][col] = -987654321;
        }
    }

    // Initial conditions
    xmx[0][0] = 0;
}