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
    float term1 = fmp[k - 1] * hmm->t[k - 1][0];
    float term2 = fdp[k - 1] * hmm->t[k - 1][5];
    float base = term1 + fip[k - 1] + term2 + hmm->begin[k];
    
    fmp[k] = base;
    fdp[k] = fmp[k - 1] * hmm->t[k - 1][2] + fdp[k - 1] * hmm->t[k - 1][6];

    if (fmp[k] <= 0.0f || fdp[k] <= 0.0f) {
        continue;
    }

    if (k < hmm->M) {
        fip[k] = fmp[k] * hmm->t[k][1];
    }

    float total = fmp[k] + fdp[k];
    fmp[k] /= total;
    fdp[k] /= total;
}
}
