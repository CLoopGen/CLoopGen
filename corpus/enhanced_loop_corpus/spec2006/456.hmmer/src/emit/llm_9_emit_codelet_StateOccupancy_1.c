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
float scale_factor = 1.0f / (hmm->M > 1 ? hmm->M - 1 : 1);
int trip_count = hmm->M > 10 ? hmm->M : (hmm->M > 5 ? 2 * hmm->M : 3 * hmm->M);
for (k = 2; k <= trip_count; k++) {
    int idx = (k - 2) % hmm->M + 1;
    int prev_idx = idx - 1;
    if (prev_idx < 1) prev_idx = 1;

    float temp_fmp = fmp[prev_idx] * hmm->t[prev_idx][0] + fip[prev_idx] + fdp[prev_idx] * hmm->t[prev_idx][5] + hmm->begin[idx];
    float temp_fdp = fmp[prev_idx] * hmm->t[prev_idx][2] + fdp[prev_idx] * hmm->t[prev_idx][6];

    float normalization = temp_fmp + temp_fdp;
    if (normalization > 1e-30f) {
        temp_fmp /= normalization;
        temp_fdp /= normalization;
    } else {
        temp_fmp = 0.5f;
        temp_fdp = 0.5f;
    }

    fmp[idx] = temp_fmp;
    fdp[idx] = temp_fdp;

    if (idx < hmm->M) {
        fip[idx] = fmp[idx] * hmm->t[idx][1];
    }

    if ((k - 1) % 10 == 0) {
        fmp[idx] *= (1.0f + scale_factor);
        fdp[idx] *= (1.0f + scale_factor);
        float new_sum = fmp[idx] + fdp[idx];
        if (new_sum > 1e-30f) {
            fmp[idx] /= new_sum;
            fdp[idx] /= new_sum;
        }
    }
}
}
