#include <stdio.h>

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


extern struct plan7_s *hmm;
extern float *fmp;
extern float *fip;
extern float *fdp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k <= hmm->M; k++) {
    if (hmm->t[k - 1][0] == 0.0f && hmm->t[k - 1][5] == 0.0f) {
        fmp[k] = fip[k - 1] + hmm->begin[k];
    } else {
        fmp[k] = fmp[k - 1] * hmm->t[k - 1][0] + fip[k - 1] + fdp[k - 1] * hmm->t[k - 1][5] + hmm->begin[k];
    }
    fdp[k] = fmp[k - 1] * hmm->t[k - 1][2] + fdp[k - 1] * hmm->t[k - 1][6];
    if (k < hmm->M) {
        fip[k] = fmp[k] * hmm->t[k][1];
    }
    float sum = fmp[k] + fdp[k];
    if (sum != 0.0f) {
        fmp[k] /= sum;
        fdp[k] /= sum;
    } else {
        fmp[k] = 0.0f;
        fdp[k] = 0.0f;
    }
}
}
