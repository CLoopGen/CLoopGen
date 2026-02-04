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

char *dsq;
int L;
struct plan7_s *hmm;
int **xmx;
int **mmx;
int **imx;
int **dmx;
int k;

void init_vars() {
    L = 1000;
    dsq = (char*)malloc((L + 1) * sizeof(char));
    for (int i = 0; i <= L; i++) {
        dsq[i] = (char)(4 + (i % 4)); // Simulate DNA sequence: values 4,5,6,7
    }

    hmm = (struct plan7_s*)malloc(sizeof(struct plan7_s));
    hmm->M = 100;
    hmm->esc = (int*)malloc((hmm->M + 1) * sizeof(int));
    hmm->msc = (int**)malloc(8 * sizeof(int*));
    for (int i = 0; i < 8; i++) {
        hmm->msc[i] = (int*)malloc((hmm->M + 1) * sizeof(int));
        for (int j = 1; j <= hmm->M; j++) {
            hmm->msc[i][j] = (i + j) % 100 - 50;
        }
    }
    for (int i = 1; i <= hmm->M; i++) {
        hmm->esc[i] = i % 100 - 50;
    }

    xmx = (int**)malloc((L + 1) * sizeof(int*));
    mmx = (int**)malloc((L + 1) * sizeof(int*));
    imx = (int**)malloc((L + 1) * sizeof(int*));
    dmx = (int**)malloc((L + 1) * sizeof(int*));

    for (int i = 0; i <= L; i++) {
        xmx[i] = (int*)calloc(2, sizeof(int));
        mmx[i] = (int*)malloc((hmm->M + 1) * sizeof(int));
        imx[i] = (int*)malloc((hmm->M + 1) * sizeof(int));
        dmx[i] = (int*)malloc((hmm->M + 1) * sizeof(int));
        for (int j = 1; j <= hmm->M; j++) {
            mmx[i][j] = -987654321;
            imx[i][j] = -987654321;
            dmx[i][j] = -987654321;
        }
    }

    xmx[L][1] = 1000;
}