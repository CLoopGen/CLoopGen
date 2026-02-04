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
    float sum_denom;
    for (k = 2; k <= hmm->M; k++) {
        float prev_fmp = fmp[k - 1];
        float prev_fdp = fdp[k - 1];
        float t_val_0 = hmm->t[k - 1][0];
        float t_val_5 = hmm->t[k - 1][5];
        float t_val_2 = hmm->t[k - 1][2];
        float t_val_6 = hmm->t[k - 1][6];

        fmp[k] = prev_fmp * t_val_0 + fip[k - 1] + prev_fdp * t_val_5 + hmm->begin[k];
        fdp[k] = prev_fmp * t_val_2 + prev_fdp * t_val_6;

        if (k < hmm->M) {
            fip[k] = fmp[k] * hmm->t[k][1];
        }

        sum_denom = fmp[k] + fdp[k];
        fmp[k] /= sum_denom;
        fdp[k] /= sum_denom;
    }
}
